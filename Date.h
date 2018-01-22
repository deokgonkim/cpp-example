
class Date {
public:
    void Print() const;
    void CopyFrom(Date otherDate);
    Date(int initMo, int initDay, int initYr, const char* msgStr);
    Date(const Date& otherDate);
    ~Date();

private:
    int mo;
    int day;
    int yr;
    char* msg;
};
