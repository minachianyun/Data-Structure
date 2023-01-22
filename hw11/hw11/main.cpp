#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string name;
    int score;
    int id;

    bool operator<(const Student &b) const {
        if (score == b.score) {
            return name > b.name;
        }
        return score < b.score;
    }

    bool operator==(const Student &b) const {
        return score == b.score && name == b.name;
    }
};

void quickSort(vector<Student> &students, int left, int right, int &curPivot) {
    if (left >= right) {
        return;
    }
    Student pivot = students[left];
    int i = left + 1, j = right;
    while (i <= j) {
        while (pivot < students[j] && i <= j) {
            j--;
        }

        while (students[i]<pivot && i <= j) {
            i++;
        }

        if(i>=j){
            break;
        }
        swap(students[i], students[j]);
        i++;
        j--;
    }
    swap(students[left], students[j]);
    curPivot++;
    printf("The index of the %d-th pivot is %d.\n", curPivot, j);
    quickSort(students, left, j - 1, curPivot);
    quickSort(students, j + 1, right, curPivot);
}

int main() {
    int N;
    cin >> N;
    vector<Student> students(N, Student());
    for (int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].score;
        students[i].id = i;
    }
    int curPivot = 0;
    quickSort(students, 0, N - 1, curPivot);
    for (int i = 0; i < N; i++) {
        printf("%s %d\n", students[i].name.c_str(), students[i].score);
    }

}
