import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Collections;

public class WordSearch
{
    ArrayList<String> m_dictionaryWords = new ArrayList<String>();
    BufferedReader br;
    String word;
    String file;

    public WordSearch(String file, String word)
    {
        this.file = file;
        this.word = word;
    }

public boolean init()
{
    try
    {
        br = new BufferedReader(new FileReader(file));
        while(br.ready())
            m_dictionaryWords.add(br.readLine());
    }catch(Exception e)
    {
        System.out.println(e.getMessage());
    }
    Collections.sort(m_dictionaryWords);

    int result = binarySearch(m_dictionaryWords,word);

    if(result >= 0)
    {
        System.out.println("Found at " + result);
        return true;
    }

    return false;
}

int compareTo(String a, String b)
{
    int lenA = a.length();
    int lenB = b.length();

    for(int i=0, j=0; i < lenA && j < lenB; i++, j++)
    {
        if(a.charAt(i) > b.charAt(j))
            return 1;
        if(a.charAt(i) < b.charAt(j))
            return -1;
    }

    return (lenA == lenB)? 0 :lenA > lenB ? 1 : -1;
}

public int binarySearch(ArrayList<String> s, String cad)
{
    int p = 0;
    int q = s.size()-1;
    int m;

    while(p <= q)
    {
        m =(p+q)/2;
        int result = compareTo(cad,s.get(m));
        if(result == 0)
            return m;
        else if(result > 0)
            p = m+1;
        else
            q = m-1;
    }
    return -1;
}

}
