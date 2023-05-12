#include "Param2048.h"

void render(int** field)
{
    /*отрисовка поля*/
    system("cls");
    for (int i = 0; i < MARGIN; i++)
    {
        cout << endl;
    }
    int size1 = _msize(field) / sizeof(field[0]);
    int size2 = _msize(field[0]) / sizeof(field[0][0]);
    cout << setw(MARGIN + 1) << "|";
    for (int i = 0; i < size1; i++)
    {
        cout << "-----|";
    }
    cout << endl;

    for (int i = 0; i < size1; i++)
    {
        for (int k = 0; k < MARGIN; k++)
        {
            cout << " ";
        }
        cout << "|";
        for (int j = 0; j < size2; j++)
        {
            if (field[i][j] == 0)
            {
                cout << "     |";
            }
            else
            {
                cout << setw(5) << field[i][j] << "|";
            }
        }
        cout << endl;
    }
    cout << setw(MARGIN + 1) << "|";
    for (int i = 0; i < size1; i++)
    {
        cout << "-----|";
    }
    cout << endl;
}

int endGame(int** field)
{
    /*функция конца игры*/

    int size1 = _msize(field) / sizeof(field[0]);
    int size2 = _msize(field[0]) / sizeof(field[0][0]);
    /*счетчик нулевых ячеек поля*/
    int counter_nulfield = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (field[i][j] == 0) counter_nulfield++;

        }
    }
    return counter_nulfield;
}
void addCelldown(int** field)
{

    /*двойки или четверки появляются внизу*/

    int size1 = _msize(field) / sizeof(field[0]);
    int size2 = _msize(field[0]) / sizeof(field[0][0]);

    /* определяем сколько нулевых ячеек внизу таблицы*/
    int counter_nal = 0;
    for (int i = 0; i < size2 - 1; i++)
    {
        if (field[size1 - 1][i] == 0)
            counter_nal++;
    }
    /*если нулевых ячеек больше двух- ставим в две из них 4- с вероятностью 25 % или 2 - с вероятностью 75 % */

    if (counter_nal >= 2)
    {
        int counter = 0;
        do
        {
            int m = random(0, size2 - 1);
            if (field[size1 - 1][m] == 0)
            {
                int l = random(0, 3) == 0 ? 4 : 2;
                field[size1 - 1][m] = l;
                counter++;
            }
        } while (counter < 2);
    }
}

void addCellup(int** field)
{
    /*двойки или четверки появляются вверху*/

    int size1 = _msize(field) / sizeof(field[0]);
    int size2 = _msize(field[0]) / sizeof(field[0][0]);

    /* определяем сколько нулевых ячеек вверху таблицы*/
    int counter_nal = 0;
    for (int i = 0; i < size2 - 1; i++)
    {
        if (field[0][i] == 0)
            counter_nal++;
    }
    /*если нулевых ячеек больше двух- ставим в две из них 4- с вероятностью 25 % или 2 - с вероятностью 75 % */
    if (counter_nal >= 2)
    {
        int counter = 0;
        do
        {
            int m = random(0, size2 - 1);
            if (field[0][m] == 0)
            {
                int l = random(0, 3) == 0 ? 4 : 2;
                field[0][m] = l;
                counter++;
            }
        } while (counter < 2);
    }

}

void addCellleft(int** field)
{
    /*двойки или четверки появляются слева*/

    int size1 = _msize(field) / sizeof(field[0]);
    int size2 = _msize(field[0]) / sizeof(field[0][0]);

    /* определяем сколько нулевых ячеек слева в  таблице*/
    int counter_nal = 0;
    for (int i = 0; i < size1 - 1; i++)
    {
        if (field[i][0] == 0)
            counter_nal++;
    }
    /*если нулевых ячеек больше двух- ставим в две из них 4- с вероятностью 25 % или 2 - с вероятностью 75 % */

    if (counter_nal >= 2)
    {
        int counter = 0;
        do
        {
            int m = random(0, size1 - 1);
            if (field[m][0] == 0)
            {
                int l = random(0, 3) == 0 ? 4 : 2;
                field[m][0] = l;
                counter++;
            }
        } while (counter < 2);
    }

}

void addCellright(int** field)
{
    /*двойки или четверки появляются справа*/

    int size1 = _msize(field) / sizeof(field[0]);
    int size2 = _msize(field[0]) / sizeof(field[0][0]);

    /* определяем сколько нулевых ячеек справа в  таблице*/
    int counter_nal = 0;
    for (int i = 0; i < size1 - 1; i++)
    {
        if (field[i][size2 - 1] == 0)
            counter_nal++;
    }
    /*если нулевых ячеек больше двух- ставим в две из них 4- с вероятностью 25 % или 2 - с вероятностью 75 % */

    if (counter_nal >= 2)
    {
        int counter = 0;
        do
        {
            int m = random(0, size1 - 1);
            if (field[m][size2 - 1] == 0)
            {
                int l = random(0, 3) == 0 ? 4 : 2;
                field[m][size2 - 1] = l;
                counter++;
            }
        } while (counter < 2);
    }

}


int main()
{
    srand(time(NULL));
    int** field = new int* [SIZE_FIELD];
    for (int i = 0; i < SIZE_FIELD; i++)
    {
        field[i] = new int[SIZE_FIELD];
        for (int j = 0; j < SIZE_FIELD; j++)
        {
            field[i][j] = 0;
        }
    }
    render(field);
    bool flag = true;
    while (flag)
    {
        char ch;
        cin >> ch;
        if (endGame(field) <= 2)
        {
            cout << "    GAME OVER";
            break;
        }
        if (ch == 'D' || ch == 'd')
        {
            addCellleft(field);
            render(field);

            for (int i = 0; i < SIZE_FIELD; ++i)
            {
                for (int j = SIZE_FIELD - 2; j >= 0; --j)
                {
                    if (field[i][j] != 0)
                    {
                        int k = j;
                        while (k < SIZE_FIELD - 1 && field[i][k + 1] == 0)
                        {
                            ++k;
                        }
                        if (k != j)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                        }
                        if (k < SIZE_FIELD - 1 && field[i][k + 1] == field[i][k])
                        {
                            field[i][k + 1] *= 2;
                            field[i][k] = 0;
                        }
                    }
                }
            }
        }
        else if (ch == 'A' || ch == 'a')
        {
            addCellright(field);
            render(field);

            for (int i = 0; i < SIZE_FIELD; ++i)
            {
                for (int j = 1; j < SIZE_FIELD; ++j)
                {
                    if (field[i][j] != 0)
                    {
                        int k = j;
                        while (k > 0 && field[i][k - 1] == 0)
                        {
                            --k;
                        }
                        if (k != j)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                        }
                        if (k > 0 && field[i][k - 1] == field[i][k])
                        {
                            field[i][k - 1] *= 2;
                            field[i][k] = 0;
                        }
                    }
                }
            }
        }
        else if (ch == 'S' || ch == 's')
        {
            addCellup(field);
            render(field);

            for (int j = 0; j < SIZE_FIELD; ++j)
            {
                for (int i = SIZE_FIELD - 2; i >= 0; --i)
                {
                    if (field[i][j] != 0)
                    {
                        int k = i;
                        while (k < SIZE_FIELD - 1 && field[k + 1][j] == 0)
                        {
                            ++k;
                        }
                        if (k != i)
                        {
                            field[k][j] = field[i][j];
                            field[i][j] = 0;
                        }
                        if (k < SIZE_FIELD - 1 && field[k + 1][j] == field[k][j])
                        {
                            field[k + 1][j] *= 2;
                            field[k][j] = 0;
                        }
                    }
                }
            }
        }
        else if (ch == 'W' || ch == 'w')
        {
            addCelldown(field);
            render(field);

            for (int j = 0; j < SIZE_FIELD; ++j)
            {
                for (int i = 1; i < SIZE_FIELD; ++i)
                {
                    if (field[i][j] != 0)
                    {
                        int k = i;
                        while (k > 0 && field[k - 1][j] == 0)
                        {
                            --k;
                        }
                        if (k != i)
                        {
                            field[k][j] = field[i][j];
                            field[i][j] = 0;
                        }
                        if (k > 0 && field[k - 1][j] == field[k][j])
                        {
                            field[k - 1][j] *= 2;
                            field[k][j] = 0;
                        }
                    }
                }
            }
        }
        else if (ch == 'Q')
            flag = false;
    }

}