#include<iostream>
#include<string>
using namespace std;

class MedicationEntry;
class VitalSignsCheck;
class DiagnosisNote;

class MedicationEntry {
private:
    string drugName;
    string dose;
    string timeGiven;
    
    MedicationEntry(string drug, string d, string time) 
        : drugName(drug), dose(d), timeGiven(time) {}
    
    friend class PatientRecord;
    
public:
    void display() const {
        cout << "Medication: " << drugName << ", Dose: " << dose << ", Time: " << timeGiven << endl;
    }
};

class VitalSignsCheck {
private:
    double temperature;
    int heartRate;
    string timeChecked;
    
    VitalSignsCheck(double temp, int hr, string time) 
        : temperature(temp), heartRate(hr), timeChecked(time) {}
    
    friend class PatientRecord;
    
public:
    void display() const {
        cout << "Vitals: Temperature: " << temperature << "°F, Heart Rate: " << heartRate << " bpm, Time: " << timeChecked << endl;
    }
};

class DiagnosisNote {
private:
    string noteText;
    string doctorName;
    string date;
    
    DiagnosisNote(string note, string doctor, string d) 
        : noteText(note), doctorName(doctor), date(d) {}
    
    friend class PatientRecord;
    
public:
    void display() const {
        cout << "Diagnosis: " <<endl;
    }
};

class PatientRecord {
private:
    static int nextId;
    int patientId;
    string name;
    string dob;
    
    MedicationEntry* medicationEntry;
    VitalSignsCheck* vitalSignsCheck;
    DiagnosisNote* diagnosisNote;

public:
    PatientRecord(string patientName, string dateOfBirth) 
        : name(patientName), dob(dateOfBirth) {
        patientId = ++nextId;
        
        medicationEntry = new MedicationEntry("paracetamol", "500mg", "08:00 AM");
        vitalSignsCheck = new VitalSignsCheck(98.6, 72, "09:00 AM");
        diagnosisNote = new DiagnosisNote("well", "Johnson", "2026-02-26");
        
        cout << "PatientRecord created for " << name << " (ID: " << patientId << ")" << endl;
    }
    
    ~PatientRecord() {
        delete medicationEntry;
        delete vitalSignsCheck;
        delete diagnosisNote;
        cout << "patientRecord for " << name << " has been deleted" << endl;
    }
    
    void displayRecord() const {
    
        cout << "patient ID: " << patientId << endl;
        cout << "name: " << name << endl;
        cout << "date of Birth: " << dob << endl;
        cout << "\n--- medical Entries ---" << endl;
        medicationEntry->display();
        vitalSignsCheck->display();
        diagnosisNote->display();
        
    }
};

int PatientRecord::nextId = 0;

int main() {
       
    PatientRecord* lily = new PatientRecord("Lily Smith", "1990-05-15");
    
    lily->displayRecord();
    
    cout << "\ndeleting Patient Record" << endl;
    delete lily;
    
    return 0;
}
