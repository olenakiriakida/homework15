
#include <iostream>
using namespace std;

/// <summary> 
/// creats date that we need
/// </summary> 
class DateTime
{
private:
    int day;
    int month;
    int year;

public:

    /// <summary> 
    /// a method to set day of birth 
    /// </summary> 
    /// <param name="day"></param> 
    void SetDay(int day)
    {
        if (day > 0 && day <= 31) // TO DO: february 28-29, april june 30 
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid value!\n";
            throw "ERROR!\n";
        }
    }

    /// <summary> 
    /// a method to get day of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetDay() const
    {
        return day;
    }

    /// <summary> 
    /// a method to set month of birth 
    /// </summary> 
    /// <param name="month"></param> 
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid value!\n";
            throw "ERROR!\n";
        }
    }

    /// <summary> 
    /// a method to get month of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetMonth() const
    {
        return month;
    }

    /// <summary> 
    /// a method to set year of birth 
    /// </summary> 
    /// <param name="year"></param> 
    void SetYear(int year)
    {
        this->year = year;
    }

    /// <summary> 
    /// a method to get year of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetYear() const
    {
        return year;
    }
    /// <summary>
    /// creats a constructor with a delegation
    /// </summary>

    DateTime() : DateTime(9, 4, 2005) {}

    DateTime(int day) : DateTime(day, 4, 2005) {}

    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }
    /// <summary>
    /// display our date on the screen
    /// </summary>
    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << "\n";
    }
};


istream& operator>>(istream& cin, DateTime& obj)
{
    int day, month, year;
    cout << "Type a year:\n";
    cin >> year;
    obj.SetYear(year);
    cout << "Type a month:\n";
    cin >> month;
    obj.SetMonth(month);
    cout << "Type a day:\n";
    cin >> day;
    obj.SetDay(day);
    return cin;
}

ostream& operator<<(ostream& cout, DateTime& obj)
{
    obj.Print();
    return cout;
}

/// <summary>
/// creats a student class
/// </summary>
class Student
{
private:
    string name;
    string surname;
    string father_name;
    DateTime birthday;
    string address;
    string phone_number;
    DateTime study_start;
    static int totalCountOfStudents;
    static const int maxAllowedStudents = 15;

    int* practice_rates = nullptr;
    int practice_rates_count = 0;

    int* exam_rates = nullptr;
    int exam_rates_count = 0;

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    /// <summary>
    /// creats a constructor with a delegation
    /// </summary>
public:
    Student() : Student("prismo", "the wishmaster", "almighty", { 9, 10, 2000 }, "cube", "077777777", { 12, 02, 2009 }) {
        cout << "Student has been created!" << endl;
    }

    Student(string name, string surname, string father_name, string address, string phone_number)
        : Student(name, surname, father_name, { 9, 10, 2000 }, address, phone_number, { 12, 02, 2009 }) {}

    Student(string name, string surname, string father_name, DateTime birthday, string address, string phone_number, DateTime study_start)
    {
        SetName(name);
        SetSurname(surname);
        SetFatherName(father_name);
        SetBirthday(birthday);
        SetAddress(address);
        SetPhoneNumber(phone_number);
        SetStudyStart(study_start);
    }

    /// <summary> 
   ///  it's a destructor for the class "Student" 
   /// </summary> 
    ~Student()
    {
        if (practice_rates != nullptr)
        {
            delete[] practice_rates;
            practice_rates = nullptr;
        }
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (exam_rates != nullptr)
        {
            delete[] exam_rates;
            exam_rates = nullptr;
        }

        cout << "Student #" << totalCountOfStudents << " has been destroyed\n";
        totalCountOfStudents--;
    }

    Student(const Student& other) {
        name = other.name;
        surname = other.surname;
        father_name = other.father_name;
        birthday = other.birthday;
        address = other.address;
        phone_number = other.phone_number;
        study_start = other.study_start;

        practice_rates_count = other.practice_rates_count;
        practice_rates = new int[practice_rates_count];
        for (int i = 0; i < practice_rates_count; ++i) {
            practice_rates[i] = other.practice_rates[i];
        }

        exam_rates_count = other.exam_rates_count;
        exam_rates = new int[exam_rates_count];
        for (int i = 0; i < exam_rates_count; ++i) {
            exam_rates[i] = other.exam_rates[i];
        }

        hometask_rates_count = other.hometask_rates_count;
        hometask_rates = new int[hometask_rates_count];
        for (int i = 0; i < hometask_rates_count; ++i) {
            hometask_rates[i] = other.hometask_rates[i];
        }

        if (totalCountOfStudents >= maxAllowedStudents)
        {
            throw runtime_error("Max number of students exceeded. Cannot create more students.");
        }
        totalCountOfStudents++;
        cout << "Student #" << totalCountOfStudents << " has been created\n";
    }

    /// <summary>
    /// creats a name
    /// </summary>
    /// <param name="name"></param>
    void SetName(string name)
    {
        this->name = name;
    }

    /// <summary>
    /// returns a name
    /// </summary>
    /// <returns></returns>
    string GetName() const
    {
        return name;
    }

    /// <summary>
    /// sets surname of a student
    /// </summary>
    /// <param name="surname"></param>
    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// returns surname of a student
    /// </summary>
    /// <returns></returns>
    string GetSurname() const
    {
        return surname;
    }

    /// <summary>
    /// sets user's father name
    /// </summary>
    /// <param name="father_name"></param>
    void SetFatherName(string father_name) {
        this->father_name = father_name;
    }

    /// <summary>
    /// returns user's father name
    /// </summary>
    /// <returns></returns>
    string GetFatherName() const {
        return father_name;
    }

private:
    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

public:

    /// <summary>
   /// a method to get birthday
   /// </summary>
   /// <returns></returns>
    DateTime GetBirthday() const
    {
        return birthday;
    }

    /// <summary>
    /// sets user's address
    /// </summary>
    /// <param name="address"></param>
    void SetAddress(string address) {
        this->address = address;
    }

    /// <summary>
    /// gets user's address
    /// </summary>
    /// <returns></returns>
    string GetAddress() const {
        return address;
    }

    /// <summary>
    /// sets user's phone number
    /// </summary>
    /// <param name="phone_number"></param>
    void SetPhoneNumber(string phone_number) {
        this->phone_number = phone_number;
    }

    /// <summary>
    /// returns user's phone number
    /// </summary>
    /// <returns></returns>
    string GetPhoneNumber() const {
        return phone_number;
    }

    /// <summary>
   /// a method to set the date of study start
   /// </summary>
   /// <param name="study_start"></param>
    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }
    /// <summary>
    /// a method to get the date of study start
    /// </summary>
    /// <returns></returns>
    DateTime GetStudyStart() const
    {
        return study_start;
    }

    /// <summary>
    /// This method involves adding a grade to the student's practice rate list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddPracticeRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (practice_rates_count == 0)
        {
            practice_rates = new int[1];
            practice_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[practice_rates_count + 1];

            for (int i = 0; i < practice_rates_count; i++)
            {
                temp[i] = practice_rates[i];
            }
            temp[practice_rates_count] = rate;

            delete[] practice_rates;

            practice_rates = temp;
        }

        practice_rates_count++;
    }

    /// <summary>
    /// shows grades for the student's practice
    /// </summary>
    void PrintPracticeRates() const
    {
        cout << "Practice rates: ";
        for (int i = 0; i < practice_rates_count; i++)
        {
            cout << practice_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// returns the practice grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetPracticeRateByIndex(unsigned int index) const
    {
        if (index >= practice_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return practice_rates[index];
    }

    /// <summary>
    ///  a method to get the practice grade count
    /// </summary>
    /// <returns></returns>
    int GetPracticeRatesCount() const
    {
        return practice_rates_count;
    }

    /// <summary>
    /// This method involves adding a grade to the student's hometask rate list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate"></param>
    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++)
                temp[i] = hometask_rates[i];
            temp[hometask_rates_count] = rate;
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }

    /// <summary>
    /// shows grades for the student's hometask
    /// </summary>
    void PrintHometaskRates() const
    {
        cout << "Hometasks rates: ";
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << hometask_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// returns the hometask grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetHometaskRateByIndex(unsigned int index) const //to get the grade by index, but without returning a pointer to the original data array, we need to add the "const" keyword to this method
    {
        if (index >= hometask_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return hometask_rates[index];
    }

    /// <summary>
    /// a method to get the hometasks grade count
    /// </summary>
    /// <returns></returns>
    int GetHometasksRatesCount() const
    {
        return hometask_rates_count;
    }

    /// <summary>
    /// This method involves adding a grade to the student's exam rate list, and the grade should be between 1 and 12 points
    /// </summary>
    /// <param name="rate"></param>
    void AddExamRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (exam_rates_count == 0)
        {
            exam_rates = new int[1];
            exam_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[exam_rates_count + 1];

            for (int i = 0; i < exam_rates_count; i++)
            {
                temp[i] = exam_rates[i];
            }
            temp[exam_rates_count] = rate;

            delete[] exam_rates;

            exam_rates = temp;
        }

        exam_rates_count++;
    }

    /// <summary>
    /// shows grades for the student's exams
    /// </summary>
    void PrintExamRates() const
    {
        cout << "Exam rates: ";
        for (int i = 0; i < exam_rates_count; i++)
        {
            cout << exam_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// returns the exam grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetExamRateByIndex(unsigned int index) const
    {
        if (index >= exam_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return exam_rates[index];
    }

    /// <summary>
    ///  a method to get the exam grade count
    /// </summary>
    /// <returns></returns>
    int GetExamRatesCount() const
    {
        return exam_rates_count;
    }

    double GetHometaskAverageRate() const
    {
        if (hometask_rates_count == 0) return 0;

        double sum = 0;
        for (int i = 0; i < hometask_rates_count; i++)
        {
            sum += hometask_rates[i];
        }
        double average = sum / hometask_rates_count;
        return average;
    }

    /// <summary>
    /// print's student's whole information, but without grades
    /// </summary>
    void ShowStudent() const {
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Father Name: " << father_name << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << phone_number << "\n";
    }

    static int GetTotalCountOfStudents()
    {
        return totalCountOfStudents;
    }

};


class Group
{
private:
    Student** students = nullptr;
    string name;
    int students_amount = 0;
    int course_number;
    string specialization;
    static int totalCountOfGroups;

public:

    /// <summary>
    /// creats a constructor with a delegation
    /// </summary>
    Group()
    {
        SetName("cosmic gate");
        SetCourseNumber(2023);
        SetSpecialization("piloting of spacecraft");
    }

    Group(const Group& group)
    {
        this->name = group.name;
        this->students_amount = group.students_amount;
        this->specialization = group.specialization;
        this->course_number = group.course_number;
        this->specialization = group.specialization;

        this->students = new Student * [this->students_amount];

        for (int i = 0; i < this->students_amount; i++)
        {
            this->students[i] = group.students[i];
        }

        totalCountOfGroups++;
        cout << "Group #" << totalCountOfGroups << " has been created\n";
    }

    ~Group()
    {
        if (students != nullptr)
        {
            for (int i = 0; i < students_amount; i++)
            {
                delete students[i];
            }
            delete[] students;
        }

        cout << "Group #" << totalCountOfGroups << " has been destroyed\n";
        totalCountOfGroups--;
    }

    /// <summary>
    /// creats a name for the group
    /// </summary>
    /// <param name="name"></param>
    void SetName(string name)
    {
        if (name != "")
        {
            this->name = name;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// returns a name for the group
    /// </summary>
    /// <returns></returns>
    string GetName() const
    {
        return name;
    }

    /// <summary>
    /// creats a number for the group
    /// </summary>
    /// <param name="course_number"></param>
    void SetCourseNumber(int course_number)
    {
        if (course_number > 0)
        {
            this->course_number = course_number;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// returns a number for the group
    /// </summary>
    /// <returns></returns>
    int GetCourseNumber() const
    {
        return course_number;
    }

    /// <summary>
    /// creats specialization for the group
    /// </summary>
    /// <param name="specialization"></param>
    void SetSpecialization(string specialization)
    {
        if (specialization != "")
        {
            this->specialization = specialization;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// returns specialization for the group
    /// </summary>
    /// <returns></returns>
    string GetSpecializationGroup() const
    {
        return specialization;
    }

    /// <summary>
    /// returns amount of the students in the group
    /// </summary>
    /// <returns></returns>
    int GetStudentsAmount() const
    {
        return students_amount;
    }

public:

    /// <summary>
    /// shows students from the group
    /// </summary>
    void ShowStudents()
    {
        cout << "Name of the group: " << name << "\n";
        cout << "Course: " << course_number << "\n";
        cout << "Specialization: " << specialization << "\n";

        if (students_amount == 0)
        {
            cout << "You don't have students in this group\n";
            return;
        }

        cout << "Students: \n";

        for (int i = 0; i < students_amount - 1; i++)
        {
            for (int j = i + 1; j < students_amount; j++)
            {
                if (students[j]->GetSurname() < students[i]->GetSurname())
                {
                    Student* temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }

        for (int i = 0; i < students_amount; i++)
        {
            cout << i + 1 << ", ";
            students[i]->ShowStudent();
        }

    }

    /// <summary>
    /// adds new student to the group
    /// </summary>
    /// <param name="new_student"></param>
    void NewStudent(const Student& new_student)
    {
        Student** temp = new Student * [students_amount + 1];

        for (int i = 0; i < students_amount; i++)
        {
            temp[i] = new Student(*students[i]);
        }

        temp[students_amount] = new Student(new_student);

        delete[] students;
        students = temp;
        students_amount++;
    }

    /// <summary>
    /// changes one group to another
    /// </summary>
    /// <param name="group2"></param>
    void ChangeGroups(Group& group2)
    {
        for (int i = 0; i < group2.GetStudentsAmount(); i++)
        {
            this->NewStudent(group2.GetStudentByIndex(i));
        }

        int k = group2.GetStudentsAmount();
        for (int i = 0; i < k; i++)
        {
            group2.DeleteFailedHomeworkStudent();
        }
    }

    /// <summary>
    /// transfers one student to another group
    /// </summary>
    /// <param name="group"></param>
    /// <param name="index"></param>
    void TransferStudent(Group& group, int index)
    {
        if (index >= 0 && index < students_amount)
        {
            group.NewStudent(*students[index]);

            for (int i = index; i < students_amount - 1; i++)
            {
                students[i] = students[i + 1];
            }

            students_amount--;
        }
    }

    /// <summary>
    /// deletes student who failed 1 exam
    /// </summary>
    void DeleteFailedExamStudent()
    {
        for (int i = 0; i < students_amount; i++)
        {
            if (students[i]->GetExamRatesCount() > 0)
            {
                int minExamRate = students[i]->GetExamRateByIndex(0);

                for (int j = 1; j < students[i]->GetExamRatesCount(); j++)
                {
                    if (students[i]->GetExamRateByIndex(j) < minExamRate)
                    {
                        minExamRate = students[i]->GetExamRateByIndex(j);
                    }
                }

                if (minExamRate < 3)
                {
                    cout << "Removing student " << students[i]->GetName() << " " << students[i]->GetSurname() << " due to failed exams." << endl;

                    for (int k = i; k < students_amount - 1; k++)
                    {
                        students[k] = students[k + 1];
                    }
                    students_amount--;
                    i--;
                }
            }
        }
    }

    /// <summary>
    /// deletes student who got the lowest average grade for homework
    /// </summary>
    void DeleteFailedHomeworkStudent()
    {
        if (students_amount == 0)
        {
            cout << "You don't have students in this group\n.";
            return;
        }

        int lowestIndex = 0;
        double lowestAverageGrade = students[0]->GetHometaskAverageRate();

        for (int i = 1; i < students_amount; i++)
        {
            double currentAverageGrade = students[i]->GetHometaskAverageRate();
            if (currentAverageGrade < lowestAverageGrade)
            {
                lowestAverageGrade = currentAverageGrade;
                lowestIndex = i;
            }
        }

        for (int i = lowestIndex; i < students_amount - 1; i++)
        {
            students[i] = students[i + 1];
        }
        students_amount--;


    }

    /// <summary>
    /// returns student after you entered his index in array
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    Student GetStudentByIndex(unsigned int index) const
    {
        if (index < students_amount)
        {
            return *students[index];
        }
        else
        {
            cout << "Incorrect index " << endl;
            throw "ERROR!";
        }
    }

    static int GetTotalCountOfGroups()
    {
        return totalCountOfGroups;
    }

};

istream& operator>>(istream& cin, Group& group)
{
    cout << "Enter group name: ";
    cin >> group.name;

    cout << "Enter course number: ";
    cin >> group.course_number;

    return cin;
}

ostream& operator<<(ostream& cout, const Group& group)
{
    cout << "Group Name: " << group.name << "\n";
    cout << "Course Number: " << group.course_number;
    return cout;
}

int Student::totalCountOfStudents;
int Group::totalCountOfGroups;

int main()
{

    Group a;
    a.SetName("Cosmic Entities");
    a.SetSpecialization("Workers");
    a.SetCourseNumber(22022);

    for (int i = 0; i < 2; i++)
    {
        Student s("auditor", "scarab", "almighty", { 15, 10, 2002 }, "cube", "077777777", { 12, 02, 20011 });
        a.NewStudent(s);
    }

    // Second Group with 16 Students
    Group b;
    b.SetName("Cube Entities");
    b.SetSpecialization("Workers");
    b.SetCourseNumber(33033);

    for (int i = 0; i < 16; i++)
    {
        Student s("prismo", "the wishmaster", "almighty", { 9, 10, 2000 }, "cube", "077777777", { 12, 02, 2009 });
        b.NewStudent(s);
    }

    cout << "Total groups created: " << Group::GetTotalCountOfGroups() << endl;
    cout << "Total students created: " << Student::GetTotalCountOfStudents() << endl;

    cout << "Amount of students in the group: " << b.GetStudentsAmount() << "\n";

    b.ShowStudents();


    a.ChangeGroups(b);
    a.ShowStudents();
    cout << "\n";

    b.TransferStudent(a, 0);
    b.ShowStudents();
    cout << "\n";

    a.DeleteFailedHomeworkStudent();
    a.ShowStudents();
    cout << "\n";

    b.DeleteFailedExamStudent();
    b.ShowStudents();
    cout << "\n";
}