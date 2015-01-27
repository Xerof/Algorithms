import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.Scanner;
import java.util.Vector;

public class Dfs {
	
	public static boolean DEBUG = false;
	
	public static void start (String file) throws Exception
	{
		Grafo myGraphs[];
		boolean G_Visited[];
		Pair<Grafo[], boolean[]> pair = null;
		File input = new File(file);
		Scanner in = new Scanner(input);
		int V;
		int E;
		
		// Get the source where the DFS will start
		int source = in.nextInt();
		//Get the vertices
		V = in.nextInt();
		//Get the edges
		E = in.nextInt();
		
		if(DEBUG)
		System.out.println("Vertices: " + V + " Edges: " + E);
		
		//Create the Array with the number of Vertices
		pair = initGraph(V);
		//Get the list of neighborhoods
		myGraphs =  pair.getFirst();
		//Get the Array of booleans
		G_Visited = pair.getSecond();
		
		for(int i = 0; i < E; i++)
		{
			int x = in.nextInt();
			int y = in.nextInt();
			
			insert(myGraphs[x],y);
		}
		
		dfs(myGraphs,G_Visited, source);
		
		if(DEBUG){
			for(int i = 0; i < V; i++)
			{
				System.out.println("[" + i + "]" + myGraphs[i]);
				System.out.println("[" + i + "]" + G_Visited[i]);
			}
		}
	}
	
	public static Pair<Grafo[], boolean[]> initGraph(int V)
	{
		Grafo Graphs[] = new Grafo[V];
		boolean G_State[] = new boolean[V];		
		for (int i = 0; i < V; i++)
		{
			Graphs[i] = new Grafo();
			Graphs[i].setName(""+ i);
			G_State[i] = false;
		}
		
		return new Pair<Grafo[], boolean[]>(Graphs, G_State);
	}
	
	public static void insert(Grafo G, int y)
	{
		Grafo temp = null;
				
		if(G.getVecino() == Grafo.INVALID){
			G.setVecino(y);
			if(DEBUG)
				System.out.println("insert "+ G);
		}else{
			if(G.getNextGrafo() == null){
				temp = new Grafo(y);
				temp.setName("");
				G.setNextGraph(temp);
			}else{
				temp = G;
				G = new Grafo(y);
				G.setNextGraph(temp);
				G.setName("");
			 }
		}	
	}
	
	public static void dfs(Grafo G[],boolean visited[], int source )
	{
		System.out.println ( "Source " + source);
		Grafo root = G[source];
		visited[source] = true;
		
		
		while(root != null)
		{
			if(root.getVecino() != Grafo.INVALID  
					&& !visited[root.getVecino()])
				dfs(G,visited,root.getVecino());
			
			root = root.getNextGrafo();
		}	
	}

}
