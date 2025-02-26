#include <iostream>
using namespace std;

class ILogger {
public:
    virtual void Log(const string& logText) = 0;
};

class FileLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << "Сохранение лога в файл... " << logText << endl;
    }
};

class DatabaseLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << "Сохранение лога в базу данных... " << logText << endl;
    }
};

class SmtpMailer {
private:
    ILogger* logger;
public:
    SmtpMailer(ILogger& log) : logger(&log) {}

    void SetLogger(ILogger& newLogger) {
        logger = &newLogger;
    }

    ILogger& GetLogger() const {
        return *logger;
    }

    void SendMessage(const string& message) {
        logger->Log("Отправка email: " + message);
        cout << "Email отправлен: " << message << endl;
    }
};

int main() {
    FileLogger fileLogger;
    SmtpMailer mailer1(fileLogger);
    mailer1.SendMessage("Проверка лога (текстовый файл)");

    DatabaseLogger dbLogger;
    mailer1.SetLogger(dbLogger); 
    mailer1.SendMessage("Проверка лога (база данных)");

    cout << "-----------------------\n";
    return 0;
}