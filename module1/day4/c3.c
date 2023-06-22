#include <stdio.h>


struct TimePeriod {
    int hours;
    int minutes;
    int seconds;
};


struct TimePeriod calculate_time_difference(struct TimePeriod start, struct TimePeriod end) {
    struct TimePeriod diff;

    int start_seconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int end_seconds = end.hours * 3600 + end.minutes * 60 + end.seconds;
    int diff_seconds = end_seconds - start_seconds;

    diff.hours = diff_seconds / 3600;
    diff_seconds %= 3600;
    diff.minutes = diff_seconds / 60;
    diff.seconds = diff_seconds % 60;

    return diff;
}

int main() {
    struct TimePeriod start, end, difference;

 
    printf("Enter the starting time period:\n");
    printf("Hours: ");
    scanf("%d", &start.hours);
    printf("Minutes: ");
    scanf("%d", &start.minutes);
    printf("Seconds: ");
    scanf("%d", &start.seconds);

   
    printf("Enter the ending time period:\n");
    printf("Hours: ");
    scanf("%d", &end.hours);
    printf("Minutes: ");
    scanf("%d", &end.minutes);
    printf("Seconds: ");
    scanf("%d", &end.seconds);

    
    difference = calculate_time_difference(start, end);

   
    printf("Difference between the time periods: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}

