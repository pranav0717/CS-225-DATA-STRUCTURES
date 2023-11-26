/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "schedule.h"
#include "utils.h"
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string. 
 * 
 * Your V2D should match the exact structure of the input file -- so the first row, first column
 * in the original file should be the first row, first column of the V2D.
 *  
 * @param filename The filename of a CSV-formatted text file. 
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

V2D file_to_V2D(const string &filename) {
    string file = file_to_string(filename);
    vector<string> lines;
    int num_lines = 0;

    istringstream ss(file);
    string line;

    while (getline(ss, line, '\n')) {
        lines.push_back(line);
        num_lines++;
    }

    V2D result;
    for (int i = 0; i < num_lines; i++) {
        vector<string> fields;

        int num_fields = split_string(lines[i], ',', fields);

        for (int j = 0; j < num_fields; j++) {
            fields[j] = trim(fields[j]);
        }

        result.push_back(fields);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Given a course roster and a list of students and their courses, 
 * perform data correction and return a course roster of valid students (and only non-empty courses).
 * 
 * A 'valid student' is a student who is both in the course roster and the student's own listing contains the course
 * A course which has no students (or all students have been removed for not being valid) should be removed
 * 
 * @param cv A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param student A 2D vector of strings where each row is a student ID followed by the courses they are taking
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

V2D clean(const V2D& cv, const V2D& student) {
    // Your code here!
    V2D ret;
    bool condition = true;
    while (condition) {
        for (const auto& row : cv) {
            std::vector<std::string> filtered_row = {row[0]};

            std::copy_if(
                std::next(std::begin(row)), 
                std::end(row), 
                std::back_inserter(filtered_row),
                [&](const std::string& student_id) {
                    int student_index = existingstudent(student_id, student);
                    return (student_index != -1) && takingclass(student_index, student, row[0]);
                }
            );

            if (filtered_row.size() > 1) {
                ret.push_back(filtered_row);
            }
        }
        condition = false; 
    }

    return ret;
}

int existingstudent(string student, const V2D& sv) {
    size_t i = 0;
    while (i < sv.size()) {
        if (sv[i][0] == student) {
            return i;
        }
        i++;
    }
    return -1;
}

bool takingclass(int index, const V2D & sv, string course) {
    const auto& row = sv.at(index);
    size_t i = 0;
    bool found = false;
    while (!found && i < row.size()) {
        if (row[i] == course) {
            found = true;
        }
        i++;
    }
    return found;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Given a collection of courses and a list of available times, create a valid scheduling (if possible).
 * 
 * A 'valid schedule' should assign each course to a timeslot in such a way that there are no conflicts for exams
 * In other words, two courses who share a student should not share an exam time.
 * Your solution should try to minimize the total number of timeslots but should not exceed the timeslots given.
 * 
 * The output V2D should have one row for each timeslot, even if that timeslot is not used.
 * 
 * As the problem is NP-complete, your first scheduling might not result in a valid match. Your solution should 
 * continue to attempt different schedulings until 1) a valid scheduling is found or 2) you have exhausted all possible
 * starting positions. If no match is possible, return a V2D with one row with the string '-1' as the only value. 
 * 
 * @param courses A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param timeslots A vector of strings giving the total number of unique timeslots
 */

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


V2D schedule(const V2D &courses, const std::vector<std::string> &timeslots){
    // Your code here!
    V2D course = courses;
    unsigned int i = 0;
    while (i < courses.size()) {
        V2D returned = scheduleHelperFunction(course, timeslots, i);
        if (returned.at(0).at(0) != "-1") {
            std::cout << "reaching sched" << std::endl;
            return returned;
        }
        i++;
    }

V2D ans(1, std::vector<std::string>(1, "-1"));
return ans;
}


V2D scheduleHelperFunction(const V2D& courses, const std::vector<std::string>& timeslots, int index) {
    
    std::vector<std::vector<int>> matrix(courses.size(), std::vector<int>(courses.size(), 0));

    for (unsigned i = 0; i < courses.size(); i++) {
        for (unsigned j = i; j < courses.size(); j++) {
            
//          bool comm = false;
//             for (unsigned int x = 1; x < courses[i].size(); x++) {
//                 for (unsigned int y = 1; y < courses[j].size(); y++) {
//                     for (unsigned int x = 0; x < courses[i].size(); x++) {
//                         for (unsigned int y = 0; y < courses[j].size(); y++) {
//                             if (courses[i][x] == courses[j][y]) {
//                             comm = true;
//                             break;
//                  }
//             }
//         }
//     }
// }


            unsigned int x = 1;
            bool comm = false;
            while (x < courses[i].size()) {
                unsigned int y = 1;
                while (y < courses[j].size()) {
                    unsigned int x2 = 0;
                    while (x2 < courses[i].size()) {
                        unsigned int y2 = 0;
                        while (y2 < courses[j].size()) {
                            if (courses[i][x2] == courses[j][y2]) {
                                comm = true;
                                break;
                            }
                            y2++;
                        }
                        if (comm) {
                            break;
                        }
                        x2++;
                    }
                    if (comm) {
                        break;
                    }
                    y++;
                }
                if (comm) {
                    break;
                }
                x++;
            }

            if (i != j && comm) {
                matrix.at(i).at(j) = 1;
                matrix.at(j).at(i) = 1;
            }
        }
    }

    std::cout << "Coloring poggggg???" << std::endl;

    std::vector<int> course_colors(courses.size(), -1);
    unsigned int i = index;

    for (unsigned int k = 0; k < courses.size(); k++) {
        std::vector<bool> neighbor_colors_available(timeslots.size(), false);
        for (unsigned int j = 0; j < courses.size(); j++) {
            if (matrix.at(i).at(j) == 1 && course_colors.at(j) != -1) {
                neighbor_colors_available.at(course_colors.at(j)) = true;
            }
        }
        unsigned int x = 0;
        while (x < neighbor_colors_available.size()) {
            if (!neighbor_colors_available.at(x)) {
                course_colors.at(i) = x;
                break;
            }
            x++;
        }

    bool found_color = false;
        for (unsigned int x = 0; x < neighbor_colors_available.size(); x++) {
            if (!neighbor_colors_available.at(x)) {
            course_colors.at(i) = x;
            found_color = true;
            break;
    }
}
            if (!found_color) {
            std::vector<std::string> s;
            s.push_back("-1");
            return V2D(1, s);
}

        i++;
        i = i % courses.size();
    }

     std::cout << "do i even get here?" << std::endl;


    V2D result;
        unsigned int b = 0;
        while (b < timeslots.size()) {
            std::vector<std::string> timeslot_courses;
            timeslot_courses.push_back(timeslots.at(b));
            for (unsigned int j = 0; j < course_colors.size(); j++) {
                for (unsigned int j = 0; j < course_colors.size(); j++) {
                    if (course_colors.at(j) == static_cast<int>(b)) {
                    timeslot_courses.push_back(courses.at(j).at(0));
        }
    }
}
            result.push_back(timeslot_courses);
            b++;
}

    return result;
}

