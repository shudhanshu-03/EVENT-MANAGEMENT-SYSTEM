#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Event{
    protected:
    string eventName;
    string date;
    string venue;
    float price;
    int time;
    int seats;

    public:
    Event(string eventName, string date, string venue, float price, int time, int seats) : eventName(eventName), date(date), venue(venue), price(price), time(time), seats(seats){}

    virtual void display(){
        cout << "Event Name: " << eventName << endl;
        cout << "Date: " << date << endl;
        cout << "Venue: " << venue << endl;
        cout << "Price: " << price << endl;
        cout << "Time: " << time << endl;
        cout << "Seats: " << seats << endl;
    }

    string getName () const {
        return eventName;
    }

    bool bookSeats(){
        if(seats > 0){
            seats --;
            return true;
        }
        return false;
    }

    void cancelSeats(){
        seats++;
    }
};

class Concert : public Event{
    string artist;

    public:
    Concert(string eventName, string date, string venue, float price, int time, int seats, string artist) : Event(eventName, date, venue, price, time, seats){}

    void display() const override{
        cout<<"Concert: "<<eventName<<endl;
    }
};

class EventManager{
    vector <Event*> event;
    map <string, vector<Event*>> userb;

    public:
    void addEvent(Event* e){
        event.push_back(e);
    }

    void showEvent(){
        if(event.empty()){
            cout<<"No events available"<<endl;
        }
        else{
            for(size_t i = 0; i < event.size(); i++){
                event[i]->display();
            }
        }
    }


    void bookEvent(const string& username, int index){
        if(index < 1 || index >= event.size()){
            cout<<"Invalid index"<<endl;
        } else{
            if(event[index-1]->bookSeats()){
                userb[username].push_back(event[index]);
                cout<<"Booking Confirmed"<<endl;
            }
            else{
                cout<<"Seat's not available"<<endl;
            }
        }
    }

    void cancelEvent(const string& username, int index){
        if(index < 1 || index >= userb[username].size()){
            cout<<"invalid index"<<endl;
        } else{
            userb[username][index-1]->cancelSeats();
            cout<<"Booking Cancelled"<<endl;
        }
    }
    
};

class User{
    map <string, string> users;
    string loggedInUser;

    public:
    void registerUser(const string& username, const string& password){
        users[username] = password;
    }

    void login(const string& username, const string& password){
        if(users.find(username) == users.end()){
            cout<<"User is Already Present"<<endl;
        } else {
            if(users[username] == password){
                loggedInUser = username;
                cout<<"Logged in"<<endl;
            } else{
                cout<<"Invalid password"<<endl;
            }
        }
    }
};

int main(){
    EventManager em;
    em.addEvent(new Event("Event1", "12-12-2021", "Venue1", 100, 12, 100));
    em.addEvent(new Event("Event2", "12-12-2021", "Venue2", 200, 12, 200));
    em.addEvent(new Event("Event3", "12-12-2021", "Venue3", 300, 12, 300));
    em.addEvent(new Event("Event4", "12-12-2021", "Venue4", 400, 12, 400));
    em.addEvent(new Event("Event5", "12-12-2021", "Venue5", 500, 12, 500));
    em.showEvent();
    em.bookEvent("User1", 1);
    em.bookEvent("User1", 2);
    em.bookEvent("User1", 3);
    em.bookEvent("User1", 4);
    em.bookEvent("User1", 5);
    em.bookEvent("User1", 6);
    em.bookEvent("User1", 7);
    em.bookEvent("User1", 8);
    em.bookEvent("User1", 9);
    em.bookEvent("User1", 10);
    em.bookEvent("User1", 11);
    em.bookEvent("User1", 12);
    em.bookEvent("User1", 13);
    em.bookEvent("User1", 14);
    em.bookEvent("User1", 15);
    em.bookEvent("User1", 16);
    em.bookEvent("User1", 17);
    em.bookEvent("User1", 18);
    em.bookEvent("User1", 19);
    em.bookEvent("User1", 20);
    em.bookEvent("User1", 21);
    em.bookEvent("User1", 22);
    em.bookEvent("User1", 23);
    em.bookEvent("User1", 24);
    em.bookEvent("User1", 25);
    em.bookEvent("User1", 26);
    em.bookEvent("User1", 27);
    em.bookEvent("User1", 28);
    em.bookEvent("User1", 29);
    em.bookEvent("User1", 30);
    em.bookEvent("User1", 31);
    em.bookEvent("User1", 32);
    em.bookEvent("User1", 33);  
}