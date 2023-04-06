// Fetch the previous timestamp and continue calculate how much time is used.
string timeuse(time_t time, time_t t1) {
    int x = (time - t1) / 60;
    int y = (time - t1) % 60;
    if (x == 0) {
        return "time spent: " + to_string(y) + "sec";
    }
    else {
        return "time spent: " + to_string(x) + "min " + to_string(y) + "sec";
    }
}
