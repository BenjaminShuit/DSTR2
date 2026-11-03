#ifndef TASK1_H
#define TASK1_H

#include <string>

const int MAX = 500;

// Parcel class
class Parcel {
public:
  int parcelID;
  std::string recipientName;
  std::string recipientID;
  std::string deliveryCompany;
  std::string parcelType;
  std::string arrivalDateTime;
  std::string status;
};

// Queue structure
struct Queue {
  Parcel parcels[MAX];
  int front;
  int rear;
  int count;
};

// Global variables
extern int nextParcelID;

extern Queue normalParcels;
extern Queue toBeSpecialHandling;
extern Queue toBeDelivered;
extern Queue toBeCollectParcel;
extern Queue returnedParcel;
extern Queue onHoldInvestigaton;

extern Queue *allQueue[5];
extern Parcel result[MAX];

// Queue functions
bool isFull(Queue queue);
bool isEmpty(Queue queue);
void enqueue(Parcel parcel, Queue queue);
void dequeue(Queue queue);

// Parcel registration and serving
void registerNewParcel(std::string recipientName, std::string recipientID,
                       std::string deliveryCompany, std::string parcelType,
                       std::string arrivalDateTime, std::string status);

void serveParcel(Queue queue);

// Display functions
void printParcel(Parcel parcel);
void displayAllParcel(Queue queue);

// Search functions
void searchAllMatchingParcel(std::string searchTerm, int field);
void viewParcelDetail(int parcelID);
Parcel *searchSpecificParcel(std::string parcelID);

// Processing and management
void processParcel();
void updateParcel(std::string parcelID);
void removeParcel(std::string parcelID);

#endif
