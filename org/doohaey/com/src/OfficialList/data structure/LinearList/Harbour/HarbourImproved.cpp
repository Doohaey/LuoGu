//1.修正了一个冗余谬误
//2.改进了船这一层的冗余，将船的“存在”缩小，主要以乘客为单位进行处理。
#include <cstdio>
#include <queue>

struct Passenger
{
    int time, nationality;
};

int num_ships;
int nationalities[300010] = {0}, nationalities_count = 0;
std::queue<Passenger> daily_passengers;

int main()
{
    scanf("%d", &num_ships);

    while(num_ships--)
    {
        int ship_time, number_passengers;
        scanf("%d%d", &ship_time, &number_passengers);

        for (int j = 1; j <= number_passengers; j++)
        {
            Passenger passenger;
            passenger.time = ship_time;
            scanf("%d", &passenger.nationality);
            nationalities[passenger.nationality]++;
            if (nationalities[passenger.nationality] == 1) nationalities_count++;
            daily_passengers.push(passenger);
        }

        while (ship_time - daily_passengers.front().time >= 86400)
        {
            Passenger front = daily_passengers.front();
            daily_passengers.pop();
            nationalities[front.nationality]--;
            if (nationalities[front.nationality] == 0) nationalities_count--;
        }

        printf("%d\n", nationalities_count);
    }

    return 0;
}





