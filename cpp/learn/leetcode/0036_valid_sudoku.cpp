// LeetCode 36. Valid Sudoku
// NeetCode 150 - Arrays & Hashing #7
// Determine if a 9x9 Sudoku board is valid (no duplicates in row/col/3x3 box).

#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using Board = std::vector<std::vector<char>>;

// Method 1: Three sets per row, col, box — index by (row/3)*3 + col/3 for box
// Algorithm: One pass; for each cell, check row/col/box sets; add value to all three.
// Time: O(81) = O(1), Space: O(81) = O(1)
bool method1_sets_per_row_col_box(Board& board) {
    std::vector<std::unordered_set<char>> rows(9), cols(9), boxes(9);
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            char ch = board[r][c];
            if (ch == '.') continue;
            int b = (r / 3) * 3 + (c / 3);
            if (rows[r].count(ch) || cols[c].count(ch) || boxes[b].count(ch))
                return false;
            rows[r].insert(ch);
            cols[c].insert(ch);
            boxes[b].insert(ch);
        }
    }
    return true;
}

// Method 2: Encode presence as string in single set (e.g. "r5:3", "c2:7", "b1:9")
// Algorithm: One set; add "r{row}:{ch}", "c{col}:{ch}", "b{box}:{ch}"; duplicate => invalid.
// Time: O(81), Space: O(81)
bool method2_encoded_strings_set(Board& board) {
    std::unordered_set<std::string> seen;
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            char ch = board[r][c];
            if (ch == '.') continue;
            int b = (r / 3) * 3 + (c / 3);
            std::string rr = "r" + std::to_string(r) + ":" + ch;
            std::string cc = "c" + std::to_string(c) + ":" + ch;
            std::string bb = "b" + std::to_string(b) + ":" + ch;
            if (!seen.insert(rr).second || !seen.insert(cc).second || !seen.insert(bb).second)
                return false;
        }
    }
    return true;
}

int main() {
    Board board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // method1_sets_per_row_col_box (active)
    std::cout << method1_sets_per_row_col_box(board) << std::endl;  // 1 (true)

    // method2_encoded_strings_set (commented out)
    // std::cout << method2_encoded_strings_set(board) << std::endl;

    return 0;
}
