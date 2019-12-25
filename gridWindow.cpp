// Title: Lab 6 - gridWindow.cpp
//
// Purpose: Implement the GridWindow class which bundles the behind the scenes Grid
//          class functionality with the display elements.
//
// Class: CSC 2430 Winter 2020
// Author: Max Benson and <your name>

#include <assert.h>
#include "gridWindow.h"

// Grid Titles
const string HTITLE = "A B C D E F G H I J";
const string VTITLE = "0 1 2 3 4 5 6 7 8 9";

// Implement the GridWindow class which bundles the behind the scenes Grid
//          class functionality with the display elements.
//

//
//  Constructor
GridWindow::GridWindow(string title, bool isUser) :
    _plot("Plot", HEIGHT, WIDTH),
    _plotWithLabels("PlotWithLabels", true, HTITLE, VTITLE),
    _labeledPlotWithTitle("LabeledPlotWithTitle", false, title) {
    _isUser = isUser;
    assert(5 == COLORS_MAX);
    _colors[0] = GREEN;
    _colors[1] = YELLOW;
    _colors[2] = BLUE;
    _colors[3] = MAGENTA;
    _colors[4] = CYAN;
}

//  Add the grid user interface elements to their containers.  Must be called
//      before Display is called.
//  Parameters:
//      none
//  Returns:
//      nothing
//  Possible Errors:
//      none expected
void GridWindow::Init() {
     // Create view
    _plotWithLabels.AddChild(&_plot);
    _labeledPlotWithTitle.AddChild(&_plotWithLabels);
}

//  Return a reference to the underlying VGroup so Display can be triggered on it
//  Parameters:
//      none
//  Returns:
//      a reference to the VGroup
//  Possible Errors:
//      none expected
VGroup& GridWindow::DisplayArea() {
    return _labeledPlotWithTitle;
}

//  Display the grid lines
//  Parameters:
//      none
//  Returns:
//      nothing
//  Possible Errors:
//      none expected
void GridWindow::DisplayLines() {
    // Display the grid
    for (int row = 0; row < HEIGHT; row ++) {
        for (int col = 0; col < WIDTH; col ++) {
            chtype ch;

            if (0 == col)  {
                if (row == 0) {
                    ch = ACS_ULCORNER;
                }
                else if (row == HEIGHT-1) {
                    ch = ACS_LLCORNER;
                }
                else if (row % 2 == 0) {
                    ch = ACS_LTEE;
                }
                else {
                    ch = ACS_VLINE;
                }
                _plot.Write(col, row, ch);
            }
            else if (col == WIDTH-1) {
                if (row == 0) {
                    ch = ACS_URCORNER;
                }
                else if (row == HEIGHT-1) {
                    ch = ACS_LRCORNER;
                }
                else if (row % 2 == 0) {
                    ch = ACS_RTEE;
                }
                else {
                    ch = ACS_VLINE;
                }
                _plot.Write(col, row, ch);
            }
            else if (row % 2 == 1) {
                if (col % 2 == 0) {
                    _plot.Write(col, row, ACS_VLINE);
                }
            }
            else {
                if (col % 2 == 1) {
                    ch = ACS_HLINE;
                }
                else if (row == 0) {
                    ch = ACS_TTEE;
                }
                else if (row == HEIGHT-1) {
                    ch = ACS_BTEE;
                }
                else {
                    ch = ACS_PLUS;
                }
                _plot.Write(col, row, ch);
            }
        }
    }
}

// Your work starts below this line...

//  Display the initial state of the grid
//  Parameters:
//      none
//  Returns:
//      nothing
//  Possible Errors:
//      none expected
void GridWindow::Display() {
    // You need to add code here
}

//  Fire at a square of the grid.  This method both updates the in memory Grid
//      class and also displays the shot in the UI
//  Parameters:
//      row - row number of the shot
//      column - column number of the shot
//      outcome - outcome of the shot
//  Returns:
//      success/failure
//  Possible Errors:
//      none expected
bool GridWindow::FireShot(int row, int column, Outcome& outcome) {
    // You need to add code here
    return true;
}

// For you to add:  LoadShips, RandomlyPlaceShips, DisplayShip
