#include <iostream>
#include <vector>
#include <string>

class User {
public:
    std::string username;
    std::string password;

    User(const std::string& uname, const std::string& pwd) : username(uname), password(pwd) {}
};

class Job {
public:
    std::string title;
    std::string company;
    std::string description;

    Job(const std::string& jobTitle, const std::string& jobCompany, const std::string& jobDesc)
        : title(jobTitle), company(jobCompany), description(jobDesc) {}
};

class JobPortal {
private:
    std::vector<User> users;
    std::vector<Job> jobs;

public:
    void registerUser(const std::string& username, const std::string& password) {
        users.emplace_back(username, password);
        std::cout << "User registration successful!\n";
    }

    void postJob(const std::string& jobTitle, const std::string& jobCompany, const std::string& jobDesc) {
        jobs.emplace_back(jobTitle, jobCompany, jobDesc);
        std::cout << "Job posted successfully!\n";
    }

    void displayJobs() const {
        std::cout << "\nAvailable Jobs:\n";
        for (const auto& job : jobs) {
            std::cout << "Title: " << job.title << "\nCompany: " << job.company << "\nDescription: " << job.description << "\n\n";
        }
    }
};

int main() {
    JobPortal jobPortal;

    while (true) {
        std::cout << "Job Portal Menu\n";
        std::cout << "1. Register\n";
        std::cout << "2. Post a Job\n";
        std::cout << "3. Search Jobs\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                jobPortal.registerUser(username, password);
                break;
            }
            case 2: {
                std::string jobTitle, jobCompany, jobDesc;
                std::cout << "Enter job title: ";
                std::cin.ignore();
                std::getline(std::cin, jobTitle);
                std::cout << "Enter company name: ";
                std::getline(std::cin, jobCompany);
                std::cout << "Enter job description: ";
                std::getline(std::cin, jobDesc);
                jobPortal.postJob(jobTitle, jobCompany, jobDesc);
                break;
            }
            case 3:
                jobPortal.displayJobs();
                break;
            case 4:
                std::cout << "Exiting the job portal. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
