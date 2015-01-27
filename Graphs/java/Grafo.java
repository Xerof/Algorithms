public class Grafo {
	public static final int INVALID = -1;
	private int vecino;
	private Grafo nextG;
	private String name;
	
	public Grafo()
	{
		vecino = INVALID;
		nextG = null;
	}
	public Grafo(int vecino)
	{
		this.vecino = vecino;
		nextG = null;
	}
	public Grafo(int vecino, Grafo nextG)
	{
		this.vecino = vecino;
		this.nextG = nextG;
	}
	
	public void setVecino(int vecino)
	{
		this.vecino = vecino;
	}
	
	public void setNextGraph(Grafo nextG)
	{
		this.nextG = nextG;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public Grafo getNextGrafo()
	{
		return nextG;
	}
	
	public int getVecino()
	{
		return vecino;
	}

	@Override
	public String toString() {
		return "Grafo " + name + "[vecino=" + vecino + ", nextG=" + nextG + "]";
	}
}

