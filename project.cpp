#include <iostream>
#include <vector>
#include <string>
#include <limits>


class Event {
protected:
    std::string title;
    std::string date;
public:
    Event(const std::string &t, const std::string &d) : title(t), date(d) {}

    virtual void display() const {
        std::cout << "Title: " << title << ", Date: " << date << std::endl;
    }
};


class Workshop : public Event {
    std::string topic;
public:
    Workshop(const std::string &t, const std::string &d, const std::string &tp) : Event(t, d), topic(tp) {}

    void display() const override {
        std::cout << "[Workshop] " << title << ", Date: " << date << ", Topic: " << topic << std::endl;
    }
};


class Meeting : public Event {
    std::string agenda;
public:
    Meeting(const std::string &t, const std::string &d, const std::string &a) : Event(t, d), agenda(a) {}

    void display() const override {
        std::cout << "[Meeting] " << title << ", Date: " << date << ", Agenda: " << agenda << std::endl;
    }
};

int main() {
    std::vector<Event*> events;
    int choice;

    while (true) {
        std::cout << "\n====== Event Management System ======" << std::endl;
        std::cout << "1. Add Workshop" << std::endl;
        std::cout << "2. Add Meeting" << std::endl;
        std::cout << "3. Show Events" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "=====================================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

       
        if(std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        std::cin.ignore(); // discard the newline

        switch (choice) {
            case 1: {
                std::string title, date, topic;
                std::cout << "-- Add Workshop --\n";
                std::cout << "Title: "; getline(std::cin, title);
                std::cout << "Date (YYYY-MM-DD): "; getline(std::cin, date);
                std::cout << "Topic: "; getline(std::cin, topic);
                events.push_back(new Workshop(title, date, topic));
                std::cout << "Workshop added successfully!\n";
                break;
            }
            case 2: {
                std::string title, date, agenda;
                std::cout << "-- Add Meeting --\n";
                std::cout << "Title: "; getline(std::cin, title);
                std::cout << "Date (YYYY-MM-DD): "; getline(std::cin, date);
                std::cout << "Agenda: "; getline(std::cin, agenda);
                events.push_back(new Meeting(title, date, agenda));
                std::cout << "Meeting added successfully!\n";
                break;
            }
            case 3:
                std::cout << "\n-- Events --\n";
                for (const auto& e : events) {
                    e->display();
                }
                break;
            case 4:
                std::cout << "Thank you for using the Event Management System. Goodbye!\n";
                for (const auto& e : events) {
                    delete e;
                }
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
