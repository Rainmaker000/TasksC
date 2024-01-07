#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ABITURIENT {
    string NAME;
    string GENDER;
    string SPEC;
    double EXAM[3];
};

double average_score(const ABITURIENT& abiturient) {
    double sum = 0.0;
    for (int i = 0; i < 3; ++i) {
        sum += abiturient.EXAM[i];
    }
    return sum / 3.0;
}

vector<ABITURIENT> input_abiturient() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    vector<ABITURIENT> abiturients;
    for (int i = 0; i < N; ++i) {
        ABITURIENT abiturient;
        cout << "\nEnter information for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, abiturient.NAME);
        cout << "Gender: ";
        cin >> abiturient.GENDER;
        cout << "Specialization: ";
        cin.ignore();
        getline(cin, abiturient.SPEC);
        cout << "Enter scores for three exams:\n";
        for (int j = 0; j < 3; ++j) {
            cout << "Exam " << j + 1 << ": ";
            cin >> abiturient.EXAM[j];
        }
        abiturients.push_back(abiturient);
    }

    return abiturients;
}

void display_below_passing_score(const vector<ABITURIENT>& abiturients, double passing_score) {
    cout << "\nStudents with scores below the passing score:\n";
    bool found = false;

    for (const auto& abiturient : abiturients) {
        if (average_score(abiturient) < passing_score) {
            cout << "Name: " << abiturient.NAME << ", Specialization: " << abiturient.SPEC << ", Average Score: " << average_score(abiturient) << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No students scored below the passing score." << endl;
    }
}

int main() {
    vector<ABITURIENT> abiturients = input_abiturient();

    sort(abiturients.begin(), abiturients.end(), [](const ABITURIENT& a, const ABITURIENT& b) {
        return average_score(a) < average_score(b);
    });

    double passing_score;
    cout << "\nEnter the passing score: ";
    cin >> passing_score;

    display_below_passing_score(abiturients, passing_score);

    return 0;
}



