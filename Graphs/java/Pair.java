public class Pair<G, S>
{
	private G first;
	private S second;
	
	public Pair(G first, S second)
	{
		this.first = first;
		this.second = second;
	}
	
	public G getFirst()
	{
		return first;
	}
	
	public S getSecond()
	{
		return second;
	}
}
