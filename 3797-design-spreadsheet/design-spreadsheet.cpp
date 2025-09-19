class Spreadsheet {
public:
    vector<vector<int>> grid;
    int numRows;

    Spreadsheet(int rows) {
        numRows = rows;
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = 0;
        for (int i = 1; i < cell.size(); i++) {
            row = row * 10 + (cell[i] - '0');
        }
        grid[row - 1][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = 0;
        for (int i = 1; i < cell.size(); i++) {
            row = row * 10 + (cell[i] - '0');
        }
        grid[row - 1][col] = 0;
    }
    
    int getValue(string formula) {
          formula = formula.substr(1);

    int plusPos = formula.find('+');
    string left = formula.substr(0, plusPos);
    string right = formula.substr(plusPos + 1);

    int leftVal, rightVal;

    if (isupper(left[0])) { 
        int col = left[0] - 'A';
        int row = 0;
        for (int i = 1; i < (int)left.size(); i++) {
            row = row * 10 + (left[i] - '0');
        }
        leftVal = grid[row - 1][col];
    } else {
        leftVal = stoi(left);
    }

 
    if (isupper(right[0])) { 
        int col = right[0] - 'A';
        int row = 0;
        for (int i = 1; i < (int)right.size(); i++) {
            row = row * 10 + (right[i] - '0');
        }
        rightVal = grid[row - 1][col];
    } else {
        rightVal = stoi(right);
    }

    return leftVal + rightVal;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */