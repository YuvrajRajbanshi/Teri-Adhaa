package nQueens;

/**
 * Queen
 */
public
class Queen
{

public
    static boolean isSafe(char board[][], int row, int col)
    {
        // vertical up
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // diagonal left up buddy
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {

            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        // diagonal right buddy
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++)
        {
            if (board[i][j] == 'Q')
            {

                return false;
            }
        }

        return true;
    }

public
    static void nQueen(char board[][], int row)
    {
        if (row == board.length)
        {
            printBoard(board);
            return;
        }
        // column loop
        for (int j = 0; j < board.length; j++)
        {

            // will chec the false or true
            if (isSafe(board, row, j))
            {
                board[row][j] = 'Q';
                nQueen(board, row + 1); // function call
                board[row][j] = 'X';    // backtracking step
            }
        }
    }

public
    static void printBoard(char board[][])
    {
        System.out.println("----------- chess board -------");

        for (int i = 0; i < board.length; i++)
        {
            for (int j = 0; j < board.length; j++)
            {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

public
    static void main(String[] args)
    {
        int n = 4;
        char board[][] = new char[n][n];

        // initialize
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                board[i][j] = 'X';
            }
        }

        nQueen(board, 0);

        // System.out.println(isSafe(board, i, j) ? "" : "Sorry we can't fullfil your
        // wish");
    }
}