/*
Problem : Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
          For example, given [(30, 75), (0, 50), (60, 150)], you should return 2

Solution : Sort the intervals on the ending time and then count the rooms required
*/
#include<iostream>
#include<algorithm>
using namespace std;
int countRooms(int startT[],int endT[],int len)
{
    //sort the start and ending times of the classes
    sort(startT,startT+len);
    sort(endT,endT+len);
    //we assume one room is already allocated for the first class
    //other classes are held in the same or different room based on the start/end times
    int rooms = 1;
    int temp_room = 1;
    int i=1,j=0;
    //continuously moving over the entire array
    while(i<len && j<len)
    {
        //checking if other activities have starting times earlier than the ending time of say class1
        //then different room is allocated to that
        if(startT[i]<=endT[j])
        {
            temp_room++;
            i++;
        //update the # of rooms
            if(temp_room>rooms)
            rooms = temp_room;
        }
        //this condition is satisfied when the start time of class 2 is after the class 1's end timing.
        //Hence the room would be empty
        else
        {
            j--;
            temp_room--;
        }
    }
    return rooms;
}
int main()
{
    int startTime[] = {30,0,60,40,10,50};
    int endTime[] = {75,50,150,110,45,70};
    int length = sizeof(startTime)/sizeof(startTime[0]);
    int res = countRooms(startTime,endTime,length);
    cout<<"The number of rooms required are : "<<res<<endl;
    return 0;
}

