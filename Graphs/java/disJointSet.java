import java.io.File;
import java.util.Scanner;

/**
 * @author fmreynad
 *
 */
public class disJointSet {
	private String fileName = null;
	private int conjSize; /* Tamaño del conjunto */
	private int conjunto[]; /* Conjunto de Datos */
	private int rank[]; /* Arreglo para guardar el tamaño de cada Conjunto */
	private int N; // Cantidad de componentes
	private int C; // Numero de conexiones
	
	public disJointSet(String file)
	{
		fileName = file;
	}
	
	public void start()
	{
		Scanner in = null;
		File file = null;
		try{
			file = new File(fileName);
			in = new Scanner(file);
			
			N = in.nextInt();
			C = in.nextInt();
			
			conjunto = new int[N];
			rank = new int[N];
			
			initCmpAndRank(conjunto, rank);
			
			for (int i = 0; i < C ; i++)
				union(in.nextInt(),in.nextInt());
				
			
			for (int i = 0; i < N ; i++)
				System.out.println(i+ " "+conjunto[i]);
			
					
		}catch(Exception e){
			System.err.println("Error: " + e.getMessage());
		}
		
	}
	
	public void initCmpAndRank(int cmp[], int rank[])
	{
		for(int i = 0; i < N; i++)
		{
			cmp[i] = i;
			rank[i] = 1;
		}
	}
	/**
	 * Function: union
	 * Description: 
	 * @param x
	 * @param y
	 */
	public void union(int x , int y)
	{
		int cmpX = find(x);
		int cmpY = find(y);
		
		if(cmpX == cmpY)
			return;
		else
			if(rank[cmpX] > rank[cmpY]){
				conjunto[cmpY] = cmpX;
				rank[cmpX] += rank[cmpY];
			}else{
				conjunto[cmpX] = cmpY;
				rank[cmpY] += rank[cmpX];
			}
				
	}
	/**
	 * Function: find
	 * Description:
	 * @param x
	 */
	public int find(int x)
	{
		return conjunto[x] == x ? x : (conjunto[x] = find(conjunto[x]));
	}
	
	public int[] getConjunto()
	{
		return conjunto;
	}
}
