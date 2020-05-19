class Student:
    def __init__(self, id_, name, year, month, day):
        self.id_ = id_
        self.name = name
        self.year = year
        self.month = month
        self.day = day

    def __lt__(self, other):
        if self.year < other.year:
            return True
        elif self.year == other.year and self.month < other.month:
            return True
        elif self.year == other.year and self.month == other.month and self.day < other.day:
            return True
        elif self.year == other.year and self.month == other.month and self.day == other.day and self.id_ > other.id_:
            return True
        return False


if __name__ == "__main__":
    n = int(input())
    students = []
    for i in range(n):
        name, year, month, day = input().split()
        students.append(Student(i, name, int(year), int(month), int(day)))

    students.sort()
    for student in students:
        print(student.name)
