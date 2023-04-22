#ifndef MYTIME_H_
#define MYTIME_H_
class Time{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        Time();
        Time(int, int = 0, int = 0);
        Time operator+(const Time & t) const;
        Time operator-(const Time & t) const;
        bool operator>(const Time & t) const;
        bool operator<(const Time & t) const; 
        void Show() const;
}

#endif
