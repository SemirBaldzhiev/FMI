#include <iostream>

#include <cstring>

enum Status {
    UNKNOWN = -1,

    UNFINISHED,
    IN_PROGRESS,
    DONE,

    COUNT_STATUS
};

class Task {

    public:
        Task() {
            setName("Default task");
            setDescription("Default description");
            setStatus(Status::UNKNOWN);
        }
        Task(const Task& other) {
            copy(other);
        }
        Task& operator=(const Task& other) {
            if (this != &other) {
                clear();
                copy(other);
            }

            return *this;
        }
        ~Task() {
            clear();
        }

        const char* getName() const {
            return name;
        }

        void setName(const char* name) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        } 

        Status getStatus() const {
            return status;
        }

        void setStatus(Status stat) {
            status = stat;
        }

        const char* getDescription() const {
            return description;
        }

        void setDescription(const char* desc) {
            description = new char[strlen(desc) + 1];
            strcpy(description, desc);
        }

        void changeStatus(Status s) {
            setStatus(s);
        }

        void taskInfo() const {
            std::cout << "Name: " << name << " Description: " << description << " Status: " << statusAsText(status) << "\n";
        }

    private:
        char* name;
        Status status;
        char* description; 

        void clear() {
            delete[] name;
            delete[] description;
        }

        void copy(const Task& other) {
            setName(other.name);
            setStatus(other.status);
            setDescription(other.description);
        }

        const char* const statusAsText(Status s) const {

            switch (s) {
                case Status::UNFINISHED: return "Unfinished";
                case Status::IN_PROGRESS: return "In Progress";
                case Status::DONE: return "Done";
                case Status::UNKNOWN: return "Unknown";
                default: return "Default status";
            }

            return nullptr;
        }

};



int main() {
    return 0;
}

