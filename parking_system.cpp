#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <cmath> // 添加对ceil函数的支持
using namespace std; // 全局变量
int cHT = 0, cWT = 0, cW, cH;
double totalFee = 0.0;
string currentDate;
vector<string> lastMenuItemsContent; // 存储菜单项的实际内容
vector<string*> lastMenuItems; // 存储指向内容的指针

// 车位状态存储
string areaA(21, '0'), areaB(16, '0'), areaC(11, '0');

// 车辆信息结构体
class Car {
public:
    string place;
    string carNumber;
    string enterTime;
    Car* next;
    
    Car(const string& p = "", const string& num = "", const string& time = "") 
        : place(p), carNumber(num), enterTime(time), next(nullptr) {}
};

// 停车区域类
class ParkingArea {
private:
    string name;
    int capacity;
    double hourlyRate;
    Car* head;
    
public:
    ParkingArea(const string& n, int cap, double rate) 
        : name(n), capacity(cap), hourlyRate(rate) {
        head = new Car(name + "01", "0");
    }
    
    ~ParkingArea() {
        Car* current = head;
        while (current) {
            Car* next = current->next;
            delete current;
            current = next;
        }
    }
    
    Car* getHead() const { return head; }
    int getCapacity() const { return capacity; }
    double getRate() const { return hourlyRate; }
    string getName() const { return name; }
    
    bool isFull() const {
        int count = 0;
        Car* temp = head->next;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count >= capacity;
    }
    
    int getOccupiedCount() const {
        int count = 0;
        Car* temp = head->next;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    vector<Car> getEmptySpots() const {
        vector<Car> emptySpots;
        string areaStatus;
        
        if (name == "A") areaStatus = areaA;
        else if (name == "B") areaStatus = areaB;
        else if (name == "C") areaStatus = areaC;
        
        for (int i = 1; i <= capacity; i++) {
            if (areaStatus[i] == '0') {
                ostringstream spotId;
                spotId << name << setw(2) << setfill('0') << i;
                emptySpots.push_back(Car(spotId.str(), "", ""));
            }
        }
        return emptySpots;
    }
    
    string getNextAvailableSpot() const {
        string areaStatus;
        
        if (name == "A") areaStatus = areaA;
        else if (name == "B") areaStatus = areaB;
        else if (name == "C") areaStatus = areaC;
        
        for (int i = 1; i <= capacity; i++) {
            if (areaStatus[i] == '0') {
                ostringstream spotId;
                spotId << name << setw(2) << setfill('0') << i;
                return spotId.str();
            }
        }
        return "";
    }
    
    bool insertCar(const string& spot, const string& carNum, const string& time) {
        if (isFull()) return false;
        
        Car* newCar = new Car(spot, carNum, time);
        Car* current = head;
        
        // 找到合适的位置插入
        while (current->next && current->next->place < spot) {
            current = current->next;
        }
        
        newCar->next = current->next;
        current->next = newCar;
        
        // 更新车位状态
        int spotNum = stoi(spot.substr(1));
        if (name == "A") areaA[spotNum] = '1';
        else if (name == "B") areaB[spotNum] = '1';
        else if (name == "C") areaC[spotNum] = '1';
        
        return true;
    }
    
    bool searchCar(const string& carNum, string& enterTime, string& spot) const {
        Car* current = head->next;
        
        while (current) {
            if (current->carNumber == carNum) {
                enterTime = current->enterTime;
                spot = current->place;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    bool removeCar(const string& carNum, string& enterTime, string& spot) {
        Car* current = head;
        
        while (current->next) {
            if (current->next->carNumber == carNum) {
                Car* temp = current->next;
                enterTime = temp->enterTime;
                spot = temp->place;
                current->next = temp->next;
                
                // 更新车位状态
                int spotNum = stoi(spot.substr(1));
                if (name == "A") areaA[spotNum] = '0';
                else if (name == "B") areaB[spotNum] = '0';
                else if (name == "C") areaC[spotNum] = '0';
                
                delete temp;
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

// 输入界面组件类
class InputUI {
public:
    int x, y, maxLength;
    string minValue, maxValue;
    
    InputUI(int xPos = 0, int yPos = 0, int len = 0, 
            const string& min = "", const string& max = "")
            : x(xPos), y(yPos), maxLength(len), minValue(min), maxValue(max) {}
};

// 全局对象实例化
ParkingArea areaSmall("A", 20, 3.0);  // 小型车区域
ParkingArea areaMedium("B", 15, 4.0); // 中型车区域
ParkingArea areaLarge("C", 10, 5.0);  // 大型车区域

vector<InputUI> inputFields = {
    {12, 1, 33, "-", ""},           // 车牌输入
    {29, 6, 3, "00", "23"},         // 小时输入
    {33, 6, 3, "00", "59"},         // 分钟输入
    {15, 6, 64, "00", "+"},         // 日期显示
    {6, 4, 33, "-", ""}             // 查询车牌输入
};

vector<InputUI> dateInputFields = {
    {17, 4, 5, "0000", ""},         // 年份输入
    {23, 4, 3, "00", "12"},         // 月份输入
};

// 辅助函数
void setPosition(int x, int y) {
    COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 修复getDisplayWidth函数，更准确地处理中文字符
int getDisplayWidth(const string& str) {
    int width = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if ((unsigned char)str[i] > 0x7F) {
            // 处理UTF-8编码的中文字符
            if ((unsigned char)str[i] >= 0xE0 && i + 2 < str.length()) {
                width += 2;  // 中文字符占两个宽度
                i += 2;      // UTF-8中文字符通常占3个字节
            } else if ((unsigned char)str[i] >= 0xC0 && i + 1 < str.length()) {
                width += 2;  // 其他双字节字符
                i += 1;
            } else {
                width += 1;  // 单字节字符
            }
        } else {
            width += 1;      // ASCII字符
        }
    }
    return width;
}

void printRepeat(int n, const string& s) {
    for (int i = 0; i < n; i++) {
        cout << s;
    }
}

void getWindowSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cW = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    cH = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    if (cWT != cW || cHT != cH) {
        system("cls");
    }
    cWT = cW;
    cHT = cH;
}

// 时间处理函数
string getCurrentTime() {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%Y%m%d%H%M", timeinfo);
    return string(buffer);
}

string formatTimeForDisplay(const string& timeStr) {
    if (timeStr.length() < 12) return timeStr;
    
    string formatted;
    formatted = timeStr.substr(0, 4) + "年" + 
               timeStr.substr(4, 2) + "月" + 
               timeStr.substr(6, 2) + "日" + 
               timeStr.substr(8, 2) + ":" + 
               timeStr.substr(10, 2);
    return formatted;
}

int timeToMinutes(const string& timeStr) {
    if (timeStr.length() < 12) return 0;
    
    int year = stoi(timeStr.substr(0, 4));
    int month = stoi(timeStr.substr(4, 2));
    int day = stoi(timeStr.substr(6, 2));
    int hour = stoi(timeStr.substr(8, 2));
    int minute = stoi(timeStr.substr(10, 2));
    
    struct tm t = {0};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = minute;
    
    time_t epochTime = mktime(&t);
    return static_cast<int>(epochTime / 60);
}

int calculateDuration(const string& inTime, const string& outTime) {
    return timeToMinutes(outTime) - timeToMinutes(inTime);
}

string getDurationText(int minutes) {
    int hours = minutes / 60;
    minutes %= 60;
    int days = hours / 24;
    hours %= 24;
    
    string result = "已停放";
    if (days > 0) {
        result += to_string(days) + "天";
    }
    if (hours > 0) {
        result += to_string(hours) + "小时";
    }
    if (minutes > 0) {
        result += to_string(minutes) + "分钟";
    }
    if (days == 0 && hours == 0 && minutes == 0) {
        result = "不足一分钟";
    }
    return result;
}

// 改进calculateFee函数，增加正确的取整和边界检查
double calculateFee(int duration, const string& parkingSpot) {
    if (duration < 0) {
        return 0.0; // 防止负数时间
    }
    
    double hours;
    if (duration <= 30) {
        hours = 0.5;
    } else {
        hours = ceil(duration / 60.0); // 正确的向上取整
    }
    
    if (parkingSpot.empty() || parkingSpot.size() < 1) {
        return 0.0; // 防止无效车位
    }
    
    if (parkingSpot[0] == 'A') return hours * 3.0;
    if (parkingSpot[0] == 'B') return hours * 4.0;
    if (parkingSpot[0] == 'C') return hours * 5.0;
    return 0.0; // 默认返回0而不是-1
}

string standardizeTime(const string& hourMinStr) {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    int hour = stoi(hourMinStr.substr(0, 2));
    int minute = stoi(hourMinStr.substr(2, 2));
    
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    
    strftime(buffer, sizeof(buffer), "%Y%m%d%H%M", timeinfo);
    return string(buffer);
}

// 文件操作函数
void saveData() {
    ofstream file("parking.txt");
    if (!file) {
        cout << "无法打开文件进行写入";
        return;
    }
    
    string now = getCurrentTime();
    file << now << " " << totalFee << endl;
    
    Car* car;
    // 保存小型车区
    car = areaSmall.getHead()->next;
    while (car) {
        file << car->place << " " << car->carNumber << " " << car->enterTime << endl;
        car = car->next;
    }
    
    // 保存中型车区
    car = areaMedium.getHead()->next;
    while (car) {
        file << car->place << " " << car->carNumber << " " << car->enterTime << endl;
        car = car->next;
    }
    
    // 保存大型车区
    car = areaLarge.getHead()->next;
    while (car) {
        file << car->place << " " << car->carNumber << " " << car->enterTime << endl;
        car = car->next;
    }
    
    file.close();
}

// 改进loadData函数，增加更健壮的错误处理
void loadData() {
    ifstream file("parking.txt");
    if (!file) {
        cout << "文件不存在，创建新的停车记录" << endl;
        // 确保currentDate已初始化，避免后续比较时出错
        currentDate = getCurrentTime().substr(0, 8);
        return;
    }
    
    string date;
    if (!(file >> date >> totalFee)) {
        cout << "文件格式错误，重置停车记录" << endl;
        currentDate = getCurrentTime().substr(0, 8);
        return;
    }
    
    string now = getCurrentTime();
    currentDate = date.substr(0, 8);
    if (currentDate != now.substr(0, 8)) {
        ofstream logFile("fee.log", ios::app);
        if (logFile) {
            logFile << date.substr(0, 4) << "年" << date.substr(4, 2) << "月" 
                << date.substr(6, 2) << "日 " << fixed << setprecision(1) << totalFee << "元" << endl;
            logFile.close();
        } else {
            cout << "无法打开日志文件" << endl;
        }
        totalFee = 0.0;
        currentDate = now.substr(0, 8);
    }
    
    string spot, carNum, enterTime;
    while (file >> spot >> carNum >> enterTime) {
        if (spot.length() < 2 || carNum.empty() || enterTime.length() < 12) {
            cout << "跳过无效记录: " << spot << " " << carNum << " " << enterTime << endl;
            continue;
        }
        
        char areaCode = spot[0];
        try {
            if (areaCode == 'A') {
                areaSmall.insertCar(spot, carNum, enterTime);
            } else if (areaCode == 'B') {
                areaMedium.insertCar(spot, carNum, enterTime);
            } else if (areaCode == 'C') {
                areaLarge.insertCar(spot, carNum, enterTime);
            }
        } catch (const exception& e) {
            cout << "处理记录时出错: " << e.what() << endl;
        }
    }
    
    file.close();
}

// UI显示函数
void displayTimeInfo() {
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y%m%d%H:%M", timeinfo);
    
    int x = 0, y = cH/2 - 4;
    setPosition(x, y);
    cout << "┌────┐";
    for (int i = 0; i < 6; i++) {
        setPosition(x, y + 1 + i);
        cout << "│";
        setPosition(x + 5, y + 1 + i);
        cout << "│";
    }
    setPosition(x, y + 7);
    cout << "└";
    printRepeat(4, "─");
    cout << "┘";
    
    setPosition(x + 1, y + 1);
    for (int i = 0; i < 4; i++) {
        cout << buffer[i];
    }
    setPosition(x + 2, y + 2);
    cout << "年";
    setPosition(x + 2, y + 3);
    for (int i = 4; i < 6; i++) {
        cout << buffer[i];
    }
    setPosition(x + 2, y + 4);
    cout << "月";
    setPosition(x + 2, y + 5);
    for (int i = 6; i < 8; i++) {
        cout << buffer[i];
    }
    setPosition(x + 2, y + 6);
    cout << "日";
}

void displayAvailableSpots() {
    getWindowSize();
    int x = cW - 6, y = cH / 2 - 4;
    setPosition(x, y);
    cout << "┌空闲┐";
    for (int i = 0; i < 6; i++) {
        setPosition(x, y + 1 + i);
        cout << "│";
        setPosition(x + 5, y + 1 + i);
        cout << "│";
    }
    setPosition(x, y + 7);
    cout << "└";
    printRepeat(4, "─");
    cout << "┘";
    
    setPosition(x + 2, y + 1);
    cout << "A区";
    setPosition(x + 2, y + 2);
    if (areaSmall.getOccupiedCount() == 20) {
        setColor(FOREGROUND_RED);
        cout << "满";
    } else {
        cout << 20 - areaSmall.getOccupiedCount();
    }
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    setPosition(x + 2, y + 3);
    cout << "B区";
    setPosition(x + 2, y + 4);
    if (areaMedium.getOccupiedCount() == 15) {
        setColor(FOREGROUND_RED);
        cout << "满";
    } else {
        cout << 15 - areaMedium.getOccupiedCount();
    }
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    setPosition(x + 2, y + 5);
    cout << "C区";
    setPosition(x + 2, y + 6);
    if (areaLarge.getOccupiedCount() == 10) {
        setColor(FOREGROUND_RED);
        cout << "满";
    } else {
        cout << 10 - areaLarge.getOccupiedCount();
    }
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// 显示菜单标题
void showTitle(const string& title, int itemCount, int x, int y) {
    setPosition(x, y - 1);
    cout << "┌──────── " << title << " ────────┐";
    --y;
    
    for (int i = 0; i < itemCount + 2; i++) {
        setPosition(x, ++y);
        cout << "│";
        setPosition(x + getDisplayWidth(title) + 19, y);
        cout << "│";
    }
    
    setPosition(x, ++y);
    cout << "└";
    printRepeat(18 + getDisplayWidth(title), "─");
    cout << "┘";
    
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// 修复showMenu函数，解决悬垂指针问题
int showMenu(vector<string> items, int selected, bool highlight) {
    getWindowSize();
    int count = items.size() - 1; // 最后一项是标题
    int x = cW / 2 - 14 - getDisplayWidth(items[count]) / 2 + 1;
    int y = cH / 2 - count / 2 - 1;
    
    // 检查是否需要重新绘制整个界面
    bool needRedraw = lastMenuItems.empty() || 
                      &items[0] != lastMenuItems[0];
    
    if (needRedraw) {
        system("cls");
    }
    
    setPosition((cW - 14) / 2, cH - 1);
    cout << "回车确定,esc返回";
    displayTimeInfo();
    displayAvailableSpots();
    
    showTitle(items[count], count, x + 4, y);
    
    if (count == 0) {
        setPosition(x + 5, y + 1);
    }
    
    // 保存菜单项的实际内容，而不是指针
    lastMenuItemsContent = items;
    lastMenuItems.clear();
    for (auto& item : lastMenuItemsContent) {
        lastMenuItems.push_back(&item);
    }
    
    for (int i = 0; i < count; i++) {
        int menuX = cW / 2 - getDisplayWidth(items[i]) / 2 + 1;
        int menuY = (cH - count - 1) / 2 + i + 1;
        
        setPosition(menuX, menuY);
        if (i == selected) {
            if (highlight)
                setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            cout << items[i];
        } else {
            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << items[i];
        }
    }
    
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}

// 选择菜单
int selectMenu(vector<string> items, bool highlight) {
    int selected = 0;
    int key;
    
    showMenu(items, selected, highlight);
    
    if (items.size() <= 1) { // 只有标题，没有选项
        return 0;
    }
    
    do {
        key = _getch();
        
        if (key == 224) { // 方向键
            key = _getch();
            switch (key) {
                case 72: // 上键
                    selected = (selected - 1 + items.size() - 1) % (items.size() - 1);
                    break;
                case 80: // 下键
                    selected = (selected + 1) % (items.size() - 1);
                    break;
            }
            showMenu(items, selected, highlight);
        } else if (key == 13) { // 回车键
            return selected;
        } else if (key == 27) { // ESC键
            return -1;
        }
        setPosition(0, 0);
    } while (items.size() > 1);
    
    return 0;
}

// 显示单个车辆信息
void displayCarInfo(const Car& car, int x, int y, bool selected) {
    x -= 11;
    y -= 3;
    setPosition(x, y);
    
    if (selected)
        setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    
    cout << "┌────────── " << car.place << " ──────────┐";
    
    for (int i = 0; i < 6; i++) {
        setPosition(x, y + 1 + i);
        cout << "│";
        setPosition(x + 26, y + 1 + i);
        cout << "│";
    }
    
    setPosition(x, y + 7);
    cout << "└";
    printRepeat(25, "─");
    cout << "┘";
    
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // 显示车牌号
    setPosition(x + 13 - getDisplayWidth(car.carNumber) / 2, y + 2);
    cout << car.carNumber;
    
    // 显示入场时间
    setPosition(x + 13 - 8 / 2, y + 4);
    cout << "入站时间:";
    
    string formattedTime = formatTimeForDisplay(car.enterTime);
    setPosition(x + 13 - getDisplayWidth(formattedTime) / 2, y + 5);
    cout << formattedTime;
    
    // 显示停车时长
    string now = getCurrentTime();
    string durationText = getDurationText(calculateDuration(car.enterTime, now));
    setPosition(x + 13 - getDisplayWidth(durationText) / 2, y + 6);
    cout << durationText;
}

// 显示单个空车位信息
void displayEmptySpot(const Car& spot, int x, int y, bool selected) {
    x -= 2;
    y -= 1;
    setPosition(x, y);
    
    if (selected)
        setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    
    cout << "┌空─闲┐";
    setPosition(x, y + 1);
    cout << "│ " << spot.place << " │";
    setPosition(x, y + 2);
    cout << "└";
    printRepeat(5, "─");
    cout << "┘";
    
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// 改进processInput函数，增强输入验证
void processInput(string& output, int key, const InputUI& field) {
    if (field.minValue == "-") {
        // 文本输入
        int len = output.length();
        if ((key >= 32 && key <= 127 && len < field.maxLength - 1) ||
            (key > 0x7F && len < field.maxLength - 2)) {
            output += static_cast<char>(key);
            if (key > 0x7F) {
                int nextChar = _getch();
                if (nextChar >= 0 && nextChar <= 255) { // 确保字符有效
                    output += static_cast<char>(nextChar);
                }
            }
        } else if (key == 8 && len > 0) { // 退格键
            if (len >= 2 && (unsigned char)output[len - 1] >= 0x7F) {
                output.pop_back();
            }
            output.pop_back();
        }
    } else {
        // 数字输入
        if (key >= '0' && key <= '9') {
            if (output.length() >= field.maxLength - 1) {
                // 数字移位
                string newOutput = output.substr(1) + static_cast<char>(key);
                
                // 检查是否超过最大值
                if (field.maxValue != "+" && newOutput > field.maxValue) {
                    newOutput = field.maxValue;
                }
                
                output = newOutput;
            } else {
                output += static_cast<char>(key);
            }
            
            // 特殊处理月份
            if (field.maxValue == "12" && output.length() >= 2 && output > "12") {
                output = "12";
            }
        } else if (key == 8) { // 退格
            output = field.minValue;
        } else if (key == -1) { // 下箭头
            try {
                int value = stoi(output);
                value--;
                
                if (value < stoi(field.minValue)) {
                    if (field.maxValue != "+") {
                        value = stoi(field.maxValue);
                    } else {
                        value = stoi(field.minValue);
                    }
                }
                
                if (field.maxLength == 3) {
                    output = (value < 10 ? "0" : "") + to_string(value);
                } else if (field.maxLength == 5) {
                    output = (value < 1000 ? string(4 - to_string(value).length(), '0') : "") + to_string(value);
                }
            } catch (const exception& e) {
                output = field.minValue; // 出错时重置为最小值
            }
        } else if (key == -2) { // 上箭头
            try {
                int value = stoi(output);
                value++;
                
                if (field.maxValue != "+" && value > stoi(field.maxValue)) {
                    value = stoi(field.minValue);
                }
                
                if (field.maxLength == 3) {
                    output = (value < 10 ? "0" : "") + to_string(value);
                } else if (field.maxLength == 5) {
                    output = (value < 1000 ? string(4 - to_string(value).length(), '0') : "") + to_string(value);
                }
            } catch (const exception& e) {
                output = field.minValue; // 出错时重置为最小值
            }
        }
        
        // 确保值在合法范围内
        try {
            if (output < field.minValue) {
                output = field.minValue;
            }
            
            if (field.maxValue != "+" && output > field.maxValue) {
                output = field.maxValue;
            }
        } catch (const exception& e) {
            output = field.minValue; // 出错时重置为最小值
        }
    }
}

// 显示输入框
void displayInput(const InputUI& field, const string& text, bool special, bool selected) {
    int x = cW / 2 - 18 - 12 / 2 + 1 + field.x;
    int y = cH / 2 - 5 + field.y;
    
    if (special) {
        x -= 3;
    }
    
    if (selected) {
        setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    } else {
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    
    setPosition(x + 1, y + 1);
    cout << text;
    
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    if (field.maxValue == "23") {
        cout << ":";
    } else if (field.maxValue != "+") {
        cout << "  ";
    }
    
    setPosition(x + 1 + getDisplayWidth(text), y + 1);
}

// 显示所有车辆或空位列表
int showAllItems(vector<Car> items, int type) {
    int scrollY = 0;
    int selected = 0;
    int itemCount = items.size();
    
    if (itemCount == 0) {
        vector<string> message = {"该区域无要求车辆", "ERROR"};
        selectMenu(message, false);
        return -1;
    }
    
    cWT = -1;
    int scrollYPrev;
    
    while (true) {
        int columnsPerRow, visibleRows;
        
        if (type == 1) { // 显示车辆
            columnsPerRow = cW / 28;
            visibleRows = (cH - 5) / 7;
        } else { // 显示空位
            columnsPerRow = cW / 10;
            visibleRows = (cH - 5) / 3;
        }
        
        if (columnsPerRow < 1) {
            columnsPerRow = 1;
        }
        
        scrollYPrev = scrollY;
        int maxRows = (itemCount + columnsPerRow - 2) / (columnsPerRow - 1); // 总行数
        
        // 在goto语句之前声明并初始化key变量
        int key = 0;
        
        if (cWT == -1) {
            goto displayItems;
        }
        
        displayTimeInfo();
        displayAvailableSpots();
        
        key = _getch();
        
        if (key == 224) { // 方向键
            key = _getch();
            switch (key) {
                case 72: // 上键
                    if ((selected - (columnsPerRow - 1)) < 0) {
                        break;
                    }
                    selected = (selected - (columnsPerRow - 1) + itemCount) % itemCount;
                    if (selected / (columnsPerRow - 1) < scrollY) {
                        scrollY = selected / (columnsPerRow - 1);
                    }
                    break;
                case 80: // 下键
                    if ((selected + (columnsPerRow - 1)) >= itemCount) {
                        selected = itemCount - 1;
                    } else {
                        selected = (selected + (columnsPerRow - 1)) % itemCount;
                    }
                    if (selected / (columnsPerRow - 1) >= scrollY + visibleRows) {
                        scrollY++;
                    }
                    break;
                case 75: // 左键
                    selected = (selected - 1 + itemCount) % itemCount;
                    if (selected < scrollY * (columnsPerRow - 1)) {
                        scrollY--;
                    }
                    if (selected == itemCount - 1) {
                        scrollY = maxRows - visibleRows;
                    }
                    break;
                case 77: // 右键
                    selected = (selected + 1) % itemCount;
                    if (selected >= (scrollY + visibleRows) * (columnsPerRow - 1)) {
                        scrollY++;
                    }
                    if (selected == 0) {
                        scrollY = 0;
                    }
                    break;
            }
        } else if (key == 13) { // 回车键
            return selected + 1;
        } else if (key == 27) { // ESC键
            return -1;
        }
        
displayItems:
        displayTimeInfo();
        displayAvailableSpots();
        
        if (scrollYPrev != scrollY) {
            system("cls");
        }
        scrollYPrev = scrollY;
        
        int showIndex = -1;
        
        if (type == 1) {
            columnsPerRow = cW / 28;
            visibleRows = (cH - 5) / 7;
        } else {
            columnsPerRow = cW / 10;
            visibleRows = (cH - 5) / 3;
        }
        
        if (columnsPerRow < 1) {
            columnsPerRow = 2;
        }
        
        int height = 0;
        
        for (int i = 0; i < itemCount; i++) {
            int row = i / (columnsPerRow - 1);
            
            if (row >= scrollY && row < scrollY + visibleRows) {
                int x = cW / columnsPerRow;
                
                if (type == 1) { // 车辆
                    displayCarInfo(items[i], x * ((i) % (columnsPerRow - 1) + 1), 4 + height, i == selected);
                    if (i == selected) {
                        showIndex = i;
                    }
                    if ((i + 1) % (columnsPerRow - 1) == 0) {
                        height += 8;
                    }
                } else { // 空位
                    displayEmptySpot(items[i], x * (i % (columnsPerRow - 1) + 1), 4 + height, i == selected);
                    if ((i + 1) % (columnsPerRow - 1) == 0) {
                        height += 3;
                    }
                }
            }
        }
        
        setPosition(cW / 2 - 13, cH - 1);
        cout << "所在行: " << selected / (columnsPerRow - 1) + 1 << "/" << maxRows 
             << "  所选项: " << (showIndex >= 0 ? showIndex + 1 : selected + 1) << "/" << itemCount << "     ";
        
        setPosition(0, 0);
        cout << "按↑↓←→切换，回车确定,esc返回";
    }
}

// 显示停车输入界面
void displayParkingInputUI(const string& title) {
    setPosition((cW - 14) / 2, cH - 1);
    cout << "回车确定,esc返回";
    
    string subtitle = "车牌号:";
    int x = cW / 2 - 18 - 12 / 2 + 1, y = cH / 2 - 5;
    
    setPosition(x, y);
    cout << "┌车型┬─────────── " << title << " ────────────────┐";
    
    for (int i = 0; i < 8; i++) {
        setPosition(x, y + 1 + i);
        if (i == 3) {
            cout << "│";
            setPosition(x + 5, y + 1 + i);
            cout << "├─────────────────────────────────────────";
        } else if (i == 6) {
            cout << "├────┤";
        } else {
            cout << "│";
            setPosition(x + 5, y + 1 + i);
            cout << "│";
        }
        
        setPosition(x + 47, y + 1 + i);
        if (i == 3) {
            cout << "┤";
        } else {
            cout << "│";
        }
    }
    
    setPosition(x + 22, y + 5);
    cout << "停车时间:";
    
    setPosition(x, y + 9);
    cout << "└────┴";
    printRepeat(41, "─");
    cout << "┘";
    
    setPosition(x + 6, y + 2);
    cout << subtitle;
}

// 显示取车输入界面
void displayExitInputUI(const string& title) {
    setPosition((cW - 14) / 2, cH - 1);
    cout << "回车确定,esc返回";
    
    string subtitle = " 车牌号:";
    int x = cW / 2 - 18 - 12 / 2 + 1, y = cH / 2 - 5;
    
    setPosition(x, y);
    cout << "┌──────────────── " << title << " ────────────────┐";
    
    for (int i = 0; i < 8; i++) {
        setPosition(x, y + 1 + i);
        cout << "│";
        setPosition(x + 47, y + 1 + i);
        cout << "│";
        
        if (i == 3) {
            setPosition(x, y + 1 + i);
            cout << "├──────────────────────────────────────────────┤";
        }
    }
    
    setPosition(x + 20, y + 5);
    cout << "取车时间:";
    
    setPosition(x, y + 9);
    cout << "└─────";
    printRepeat(41, "─");
    cout << "┘";
    
    setPosition(x + 1, y + 2);
    cout << subtitle;
}

// 显示车型选项按钮
void displayCarTypeButtons(int selected) {
    int x = cW / 2 - 18 - 12 / 2 + 2, y = cH / 2 - 3;
    
    // 大型车按钮
    setPosition(x, y);
    if (areaLarge.isFull()) {
        setColor(FOREGROUND_RED);
    } else {
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    
    if (selected == 0) {
        if (areaLarge.isFull()) {
            setColor(BACKGROUND_RED | BACKGROUND_INTENSITY);
        } else {
            setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        }
    }
    cout << "大型";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // 中型车按钮
    setPosition(x, y + 2);
    if (areaMedium.isFull()) {
        setColor(FOREGROUND_RED);
    } else {
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    
    if (selected == 1) {
        if (areaMedium.isFull()) {
            setColor(BACKGROUND_RED | BACKGROUND_INTENSITY);
        } else {
            setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        }
    }
    cout << "中型";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // 小型车按钮
    setPosition(x, y + 4);
    if (areaSmall.isFull()) {
        setColor(FOREGROUND_RED);
    } else {
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    
    if (selected == 2) {
        if (areaSmall.isFull()) {
            setColor(BACKGROUND_RED | BACKGROUND_INTENSITY);
        } else {
            setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        }
    }
    cout << "小型";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // 返回按钮
    setPosition(x, y + 6);
    if (selected == 3) {
        setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }
    cout << "返回";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// 显示车辆满额提示
void displayFullAlert() {
    system("cls");
    vector<string> message = {"该区域车位已满", "ERROR"};
    selectMenu(message, false);
    system("cls");
}

// 根据超时时间获取超时车辆
vector<Car> getOvertimeCars(ParkingArea& area, int minutes) {
    vector<Car> result;
    string now = getCurrentTime();
    Car* current = area.getHead()->next;
    
    while (current) {
        if (calculateDuration(current->enterTime, now) > minutes) {
            result.push_back(*current);
        }
        current = current->next;
    }
    
    return result;
}

// 输入处理界面
void inputInterface(const string& title, bool isExiting) {
    system("cls");
    
    // 首先声明并初始化所有可能会在goto语句之后使用的变量
    int selected = 0;
    int fieldSelected = 0;
    int key = 0;
    int key2 = 0;
    int key3 = 0;
    string inputs[3] = {"", "00", "00"};
    string dateDisplay;
    
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);
    char buffer[64];
    strftime(buffer, sizeof(buffer), "%Y年%m月%d日", timeinfo);
    dateDisplay = buffer;
    
    // 为防止使用strftime时直接向string赋值而创建临时缓冲区
    char hourBuffer[3] = {0};
    char minBuffer[3] = {0};
    strftime(hourBuffer, sizeof(hourBuffer), "%H", timeinfo);
    strftime(minBuffer, sizeof(minBuffer), "%M", timeinfo);
    inputs[1] = hourBuffer;
    inputs[2] = minBuffer;
    
    if (isExiting) {
        goto exitProcess;
    }
    
    // 停车流程
parkingTypeSelection:
    displayTimeInfo();
    displayAvailableSpots();
    displayCarTypeButtons(selected);
    displayParkingInputUI(title);
    displayInput(inputFields[0], inputs[0], false, false);
    displayInput(inputFields[1], inputs[1], false, false);
    displayInput(inputFields[2], inputs[2], false, false);
    displayInput(inputFields[3], dateDisplay, false, false);
    
    setPosition(0, 0);
    key = _getch();
    
    if (key == 224) {
        key = _getch();
        switch (key) {
            case 72: // 上键
                selected = (selected - 1 + 4) % 4;
                break;
            case 80: // 下键
                selected = (selected + 1) % 4;
                break;
        }
    } else if (key == 13) { // 回车键
        if (selected == 0 && areaLarge.isFull()) {
            displayFullAlert();
            goto parkingTypeSelection;
        } else if (selected == 1 && areaMedium.isFull()) {
            displayFullAlert();
            goto parkingTypeSelection;
        } else if (selected == 2 && areaSmall.isFull()) {
            displayFullAlert();
            goto parkingTypeSelection;
        } else if (selected == 3) { // 返回
            return;
        }
        goto inputProcess;
    } else if (key == 27) { // ESC键
        return;
    }
    goto parkingTypeSelection;

inputProcess:
    getWindowSize();
    setPosition((cW - 44) / 2, cH - 2);
    cout << "←→可以切换输入框，↑↓可以微调数字类型的输入框";
    
    if (isExiting) {
        displayExitInputUI(title);
    } else {
        displayParkingInputUI(title);
        displayCarTypeButtons(selected);
    }
    
    displayTimeInfo();
    displayAvailableSpots();
    
    displayInput(inputFields[0], inputs[0], isExiting, fieldSelected == 0);
    displayInput(inputFields[1], inputs[1], isExiting, fieldSelected == 1);
    key2 = _getch();
    
    if (key2 == 224) {
        key2 = _getch();
        switch (key2) {
            case 75: // 左键
                fieldSelected = (fieldSelected - 1 + 3) % 3;
                break;
            case 77: // 右键
                fieldSelected = (fieldSelected + 1) % 3;
                break;
            case 80: // 下键
                key2 = -1;
                goto processInput;
            case 72: // 上键
                key2 = -2;
                goto processInput;
        }
    } else if (key2 == 27) { // ESC键
        if (isExiting)
            return;
        goto parkingTypeSelection;
    } else if (key2 == 13) { // 回车键
        goto finalizeProcess;
    } else {
processInput:
        processInput(inputs[fieldSelected], key2, inputFields[fieldSelected]);
    }
    goto inputProcess;

exitProcess:
    getWindowSize();
    setPosition((cW - 44) / 2, cH - 2);
    cout << "←→可以切换输入框，↑↓可以微调数字类型的输入框";
    
    displayExitInputUI(title);
    
    displayTimeInfo();
    displayAvailableSpots();
    
    displayInput(inputFields[0], inputs[0], true, fieldSelected == 0);
    displayInput(inputFields[1], inputs[1], true, fieldSelected == 1);
    displayInput(inputFields[2], inputs[2], true, fieldSelected == 2);
    displayInput(inputFields[3], dateDisplay, true, false);
    
    key3 = _getch();
    
    if (key3 == 224) {
        key3 = _getch();
        switch (key3) {
            case 75: // 左键
                fieldSelected = (fieldSelected - 1 + 3) % 3;
                break;
            case 77: // 右键
                fieldSelected = (fieldSelected + 1) % 3;
                break;
            case 80: // 下键   
                key3 = -1;
                goto processExitInput;
            case 72: // 上键
                key3 = -2;
                goto processExitInput;
        }
    } else if (key3 == 27) { // ESC键
        return;
    } else if (key3 == 13) { // 回车键
        goto finalizeExitProcess;
    } else {
processExitInput:
        processInput(inputs[fieldSelected], key3, inputFields[fieldSelected]);
    }
    goto exitProcess;

finalizeProcess:
    // 处理停车信息
    {
        // 检查车牌是否已存在
        string dummyTime, dummySpot;
        if (areaSmall.searchCar(inputs[0], dummyTime, dummySpot) || 
            areaMedium.searchCar(inputs[0], dummyTime, dummySpot) || 
            areaLarge.searchCar(inputs[0], dummyTime, dummySpot)) {
            vector<string> message = {"请重试", "车牌号重复"};
            system("cls");
            selectMenu(message, false);
            system("cls");
            goto inputProcess;
        }
        
        // 检查时间是否合法
        string timeStr = inputs[1] + inputs[2];
        string standardizedTime = standardizeTime(timeStr);
        string currentTime = getCurrentTime();
        
        if (standardizedTime > currentTime) {
            string formattedCurrentTime = formatTimeForDisplay(currentTime);
            vector<string> message = {"当前时间为", formattedCurrentTime, "停车时间不能晚于当前时间"};
            system("cls");
            selectMenu(message, false);
            system("cls");
            goto inputProcess;
        }
        
        // 执行停车操作
        string spotId;
        if (selected == 0) { // 大型车
            spotId = areaLarge.getNextAvailableSpot();
            areaLarge.insertCar(spotId, inputs[0], standardizedTime);
        } else if (selected == 1) { // 中型车
            spotId = areaMedium.getNextAvailableSpot();
            areaMedium.insertCar(spotId, inputs[0], standardizedTime);
        } else if (selected == 2) { // 小型车
            spotId = areaSmall.getNextAvailableSpot();
            areaSmall.insertCar(spotId, inputs[0], standardizedTime);
        }
        
        vector<string> resultMessage = {inputs[0], spotId, "停车成功"};
        saveData();
        selectMenu(resultMessage, false);
    }
    return;

finalizeExitProcess:
    // 处理取车信息
    {
        string enterTime, spot;
        if (!(areaSmall.searchCar(inputs[0], enterTime, spot) || 
              areaMedium.searchCar(inputs[0], enterTime, spot) || 
              areaLarge.searchCar(inputs[0], enterTime, spot))) {
            vector<string> message = {"请重试", "未找到车辆"};
            selectMenu(message, false);
            goto exitProcess;
        }
        
        // 检查时间是否合法
        string timeStr = inputs[1] + inputs[2];
        string exitTime = standardizeTime(timeStr);
        
        if (exitTime < enterTime) {
            string formattedEnterTime = formatTimeForDisplay(enterTime);
            vector<string> message = {"停车时间为", formattedEnterTime, "取车时间不能早于停车时间"};
            system("cls");
            selectMenu(message, false);
            system("cls");
            goto exitProcess;
        }
        
        // 计费处理
        if (currentDate.empty()) {
            currentDate = exitTime.substr(0, 8);
        } else if (currentDate != exitTime.substr(0, 8)) {
            // 日期变更，记录收费
            ofstream logFile("fee.log", ios::app);
            logFile << currentDate.substr(0, 4) << "年" << currentDate.substr(4, 2) << "月"
                    << currentDate.substr(6, 2) << "日 " << fixed << setprecision(1) << totalFee << "元" << endl;
            logFile.close();
            totalFee = 0.0;
            currentDate = exitTime.substr(0, 8);
        }
        
        // 移除车辆
        if (spot[0] == 'A') {
            areaSmall.removeCar(inputs[0], enterTime, spot);
        } else if (spot[0] == 'B') {
            areaMedium.removeCar(inputs[0], enterTime, spot);
        } else if (spot[0] == 'C') {
            areaLarge.removeCar(inputs[0], enterTime, spot);
        }
        
        // 计算费用和停车时长
        int duration = calculateDuration(enterTime, exitTime);
        string durationText = getDurationText(duration);
        double fee = calculateFee(duration, spot);
        totalFee += fee;
        
        ostringstream feeText;
        feeText << "收费" << fixed << setprecision(1) << fee << "元";
        
        vector<string> resultMessage = {
            inputs[0], "", spot, durationText, feeText.str(), "取车成功"
        };
        
        saveData();
        selectMenu(resultMessage, false);
    }
}

// 查询特定车辆
void searchSpecificCar() {
    string carNumber;
    
    while (true) {
        system("cls");
        displayTimeInfo();
        displayAvailableSpots();
        
        int x = cW / 2 - 9, y = cH / 2;
        setPosition((cW - 14) / 2, cH - 1);
        cout << "回车确定,esc返回";
        setPosition(x - 10, y - 1);
        cout << "┌─────────── 请输入车牌号 ───────────┐";
        setPosition(x - 10, y);
        cout << "│";
        setPosition(x + 27, y);
        cout << "│";
        setPosition(x - 10, y + 1);
        cout << "└────────────────────────────────────┘";
        
        displayInput(inputFields[4], carNumber, false, true);
        
        int key = _getch();
        if (key == 13) { // 回车键
            system("cls");
            break;
        } else if (key == 27) { // ESC键
            system("cls");
            return;
        }
        processInput(carNumber, key, inputFields[4]);
    }
    
    // 查找车辆
    string enterTime, spot;
    if (!(areaSmall.searchCar(carNumber, enterTime, spot) || 
          areaMedium.searchCar(carNumber, enterTime, spot) || 
          areaLarge.searchCar(carNumber, enterTime, spot))) {
        vector<string> message = {"请重试", "未找到车辆"};
        selectMenu(message, false);
        searchSpecificCar();
        return;
    }
    
    // 显示车辆信息
    string currentTime = getCurrentTime();
    string durationText = getDurationText(calculateDuration(enterTime, currentTime));
    string formattedEnterTime = formatTimeForDisplay(enterTime);
    
    // 修复vector中的string转char*问题
    vector<string> carInfo = {
        carNumber, 
        "", 
        "停靠位置", 
        spot, 
        "进场时间", 
        formattedEnterTime, 
        durationText, 
        "已找到车辆"
    };
    
    selectMenu(carInfo, false);
}

// 统计月收入
void calculateMonthlyIncome() {
    string yearStr = "0000", monthStr = "00";
    string currentTime = getCurrentTime();
    yearStr = currentTime.substr(0, 4);
    monthStr = currentTime.substr(4, 2);
    
    dateInputFields[0].maxValue = currentTime.substr(0, 4);
    
    system("cls");
    int selected = 0;
    
    while (true) {
        displayTimeInfo();
        displayAvailableSpots();
        
        int x = cW / 2, y = cH / 2;
        setPosition((cW - 14) / 2, cH - 1);
        cout << "回车确定,esc返回";
        setPosition(x - 10, y - 1);
        cout << "┌── 目标日期输入 ──┐";
        setPosition(x - 10, y);
        cout << "│";
        setPosition(x + 9, y);
        cout << "│";
        setPosition(x - 10, y + 1);
        cout << "└──────────────────┘";
        
        displayInput(dateInputFields[0], yearStr, false, selected == 0);
        displayInput(dateInputFields[1], monthStr, false, selected == 1);
        
        setPosition(x - 1, y);
        cout << "年";
        setPosition(x + 3, y);
        cout << "月";
        
        int key = _getch();
        if (key == 224) {
            key = _getch();
            switch (key) {
                case 75: // 左键
                case 77: // 右键
                    selected = (selected + 1) % 2;
                    break;
            }
        } else if (key == 13) { // 回车键
            system("cls");
            break;
        } else if (key == 27) { // ESC键
            system("cls");
            return;
        }
        processInput(selected == 0 ? yearStr : monthStr, key, dateInputFields[selected]);
    }
    
    string targetDate = yearStr + monthStr;
    double totalIncome = 0.0;
    
    ifstream logFile("fee.log");
    string line;
    
    while (getline(logFile, line)) {
        if (line.length() < 10) continue;
        
        string year = line.substr(0, 4);
        string month = line.substr(5, 2);
        string datePrefix = year + month;
        
        if (datePrefix == targetDate) {
            // 提取金额
            size_t pos = line.find("元");
            if (pos != string::npos) {
                double amount = stod(line.substr(line.rfind(" ") + 1, pos - line.rfind(" ") - 1));
                totalIncome += amount;
            }
        }
    }
    
    // 如果是当月，加上当前未记录的收入
    if (targetDate == currentTime.substr(0, 6)) {
        totalIncome += totalFee;
    }
    
    string resultMsg;
    if (totalIncome > 0) {
        ostringstream oss;
        oss << "该月收费" << fixed << setprecision(2) << totalIncome << "元";
        resultMsg = oss.str();
    } else {
        resultMsg = "该月无收费";
    }
    
    vector<string> incomeInfo = {resultMsg, "收费情况"};
    selectMenu(incomeInfo, false);
}

// 统计超时车辆
void searchOvertimeCars() {
    string timeThreshold = "0300"; // 默认300分钟
    dateInputFields[0].maxValue = "9999";
    
    system("cls");
    
    while (true) {
        getWindowSize();
        int x = cW / 2, y = cH / 2;
        
        setPosition(x - 10, y - 1);
        cout << "┌── 超时时间输入 ──┐";
        setPosition(x - 10, y);
        cout << "│";
        setPosition(x + 9, y);
        cout << "│";
        setPosition(x - 10, y + 1);
        cout << "└──────────────────┘";
        
        displayTimeInfo();
        displayAvailableSpots();
        displayInput(dateInputFields[0], timeThreshold, false, true);
        cout << "分钟";
        
        int key = _getch();
        if (key == 224) {
            key = _getch();
            switch (key) {
                case 72: // 上键
                    key = -2;
                    break;
                case 80: // 下键
                    key = -1;
                    break;
            }
        } else if (key == 13) { // 回车键
            system("cls");
            break;
        } else if (key == 27) { // ESC键
            system("cls");
            return;
        }
        
        processInput(timeThreshold, key, dateInputFields[0]);
    }
    
    int threshold = stoi(timeThreshold);
    
    // 选择区域菜单
    vector<string> areaMenu = {
        "A区(小型车)", 
        "B区(中型车)", 
        "C区(大型车)", 
        "返回", 
        "选择区域"
    };
    
    while (true) {
        int choice = selectMenu(areaMenu, true);
        
        if (choice == -1 || choice == 3) {
            return;
        }
        
        system("cls");
        vector<Car> overtimeCars;
        
        switch (choice) {
            case 0: // A区
                overtimeCars = getOvertimeCars(areaSmall, threshold);
                break;
            case 1: // B区
                overtimeCars = getOvertimeCars(areaMedium, threshold);
                break;
            case 2: // C区
                overtimeCars = getOvertimeCars(areaLarge, threshold);
                break;
        }
        
        showAllItems(overtimeCars, 1);
        system("cls");
    }
}

// 优化main函数中的错误处理
int main() {
    try {
        // 初始化
        loadData();
        
        // 主菜单循环
        while (true) {
            try {
                // 主菜单项
                vector<string> mainMenu = {
                    "停车&&收费", 
                    "查询", 
                    "统计", 
                    "退出", 
                    "停车场管理系统"
                };
                
                int mainChoice = selectMenu(mainMenu, true);
                
                switch (mainChoice) {
                    case 0: // 停车管理
                    {
                        bool continueParking = true;
                        while (continueParking) {
                            vector<string> parkingMenu = {
                                "停车", 
                                "取车", 
                                "返回", 
                                "停车管理"
                            };
                            
                            int parkingChoice = selectMenu(parkingMenu, true);
                            
                            switch (parkingChoice) {
                                case 0: // 停车
                                    inputInterface("停车信息输入", false);
                                    system("cls");
                                    break;
                                case 1: // 取车
                                    inputInterface("取车信息输入", true);
                                    system("cls");
                                    break;
                                default: // 返回或ESC
                                    continueParking = false;
                                    break;
                            }
                        }
                        break;
                    }
                    
                    case 1: // 查询
                    {
                        bool continueQuery = true;
                        while (continueQuery) {
                            vector<string> queryMenu = {
                                "显示所有停放车辆", 
                                "显示空闲车位", 
                                "查询指定车辆", 
                                "返回", 
                                "查询"
                            };
                            
                            int queryChoice = selectMenu(queryMenu, true);
                            
                            switch (queryChoice) {
                                case 0: // 显示所有停放车辆
                                {
                                    vector<string> areaMenu = {
                                        "A区(小型车)", 
                                        "B区(中型车)", 
                                        "C区(大型车)", 
                                        "选择区域"
                                    };
                                    
                                    int areaChoice = selectMenu(areaMenu, true);
                                    
                                    system("cls");
                                    
                                    switch (areaChoice) {
                                        case 0:
                                        {
                                            // 获取A区所有车辆
                                            vector<Car> cars;
                                            Car* current = areaSmall.getHead()->next;
                                            while (current) {
                                                cars.push_back(*current);
                                                current = current->next;
                                            }
                                            showAllItems(cars, 1);
                                            break;
                                        }
                                        case 1:
                                        {
                                            // 获取B区所有车辆
                                            vector<Car> cars;
                                            Car* current = areaMedium.getHead()->next;
                                            while (current) {
                                                cars.push_back(*current);
                                                current = current->next;
                                            }
                                            showAllItems(cars, 1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            // 获取C区所有车辆
                                            vector<Car> cars;
                                            Car* current = areaLarge.getHead()->next;
                                            while (current) {
                                                cars.push_back(*current);
                                                current = current->next;
                                            }
                                            showAllItems(cars, 1);
                                            break;
                                        }
                                    }
                                    break;
                                }
                                
                                case 1: // 显示空闲车位
                                {
                                    vector<string> areaMenu = {
                                        "A区(小型车)", 
                                        "B区(中型车)", 
                                        "C区(大型车)", 
                                        "选择区域"
                                    };
                                    
                                    int areaChoice = selectMenu(areaMenu, true);
                                    
                                    system("cls");
                                    
                                    switch (areaChoice) {
                                        case 0:
                                        {
                                            vector<Car> emptySpots = areaSmall.getEmptySpots();
                                            showAllItems(emptySpots, 0);
                                            break;
                                        }
                                        case 1:
                                        {
                                            vector<Car> emptySpots = areaMedium.getEmptySpots();
                                            showAllItems(emptySpots, 0);
                                            break;
                                        }
                                        case 2:
                                        {
                                            vector<Car> emptySpots = areaLarge.getEmptySpots();
                                            showAllItems(emptySpots, 0);
                                            break;
                                        }
                                    }
                                    break;
                                }
                                
                                case 2: // 查询指定车辆
                                    searchSpecificCar();
                                    break;
                                
                                default: // 返回或ESC
                                    continueQuery = false;
                                    break;
                            }
                        }
                        break;
                    }
                    
                    case 2: // 统计
                    {
                        bool continueStats = true;
                        while (continueStats) {
                            vector<string> statsMenu = {
                                "月收入统计", 
                                "停车超过一定时间的车辆", 
                                "返回", 
                                "统计"
                            };
                            
                            int statsChoice = selectMenu(statsMenu, true);
                            
                            switch (statsChoice) {
                                case 0: // 月收入统计
                                    calculateMonthlyIncome();
                                    break;
                                
                                case 1: // 停车超时车辆统计
                                    searchOvertimeCars();
                                    break;
                                
                                default: // 返回或ESC
                                    continueStats = false;
                                    break;
                            }
                        }
                        break;
                    }
                    
                    case 3: // 退出
                    case -1: // ESC
                        return 0;
                }
            } catch (const exception& e) {
                cout << "操作过程中出错: " << e.what() << endl;
                system("pause");
                system("cls");
            }
        }
    } catch (const exception& e) {
        cout << "程序启动失败: " << e.what() << endl;
        system("pause");
        return 1;
    }
    
    return 0;
}
