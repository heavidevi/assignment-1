#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
using namespace std;

class Message {
private:
    const int messageId;
    string senderName;
    string receiverName;
    string content;
    string timestamp;
    bool isRead;
    static int totalMessagesSent;

public:
    Message(string sender, string receiver, string text) 
        : messageId(++totalMessagesSent), senderName(sender), 
          receiverName(receiver), content(text), 
          timestamp("01-03-2026"), isRead(false) {}

    void displayMessage() const {
        cout << "\n--- Message ID: " << messageId << endl;
        cout << "From: " << senderName << endl;
        cout << "To: " << receiverName << endl;
        cout << "Text: " << content << endl;
        cout << "Status: " << (isRead ? "Read" : "Unread") << endl;
    }

    void markAsRead() {
        isRead = true;
        cout << "Message " << messageId << " has been marked as read." << endl;
    }

    void editContent(string newText) {
        content = newText;
        cout << "Message content updated." << endl;
    }

    static int getTotalMessages() {
        return totalMessagesSent;
    }

    string getSender() const { return senderName; }
    int getId() const { return messageId; }

    ~Message() {}
};

int Message::totalMessagesSent = 0;

#endif