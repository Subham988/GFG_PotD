class Solution{
public:
    string stringMirror(string str)
    {
        string temp;
        temp += str[0];
        for (int i = 1; i < str.length(); i++)
        {
            if (str[0] == str[1])
                break;
            if (str[i] <= str[i-1])
                temp += str[i];
            else
                break;
        }
        temp += string(temp.rbegin(), temp.rend());
        return temp;
    }
};