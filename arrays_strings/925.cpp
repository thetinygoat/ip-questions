bool isLongPressedName(string name, string typed)
{

    int i = 0;
    int j = 0;

    while (i < name.length() && j < typed.length())
    {
        if (name[i] == typed[j])
        {
            i++;
            j++;
        }
        if (name[i] != typed[j])
        {
            if (j > 0 && typed[j] == typed[j - 1])
            {
                j++;
            }
            else
                return false;
        }
    }
    if (i == name.length() && j == typed.length())
        return true;
    return false;
}