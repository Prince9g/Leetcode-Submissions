class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
    auto it = std::lower_bound(bookings.begin(), bookings.end(), std::make_pair(start, end));
        // Check for overlap with the previous booking
        if (it != bookings.begin() && std::prev(it)->second > start) {
            return false;
        }
        // Check for overlap with the next booking
        if (it != bookings.end() && it->first < end) {
            return false;
        }
        // If no overlap, insert the booking
        bookings.insert(it, {start, end});
        return true;
    }

private:
    std::vector<std::pair<int, int>> bookings;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */