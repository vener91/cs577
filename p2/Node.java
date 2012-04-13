import java.util.*;
class Node {
	public ArrayList<Node> outBound;
	//public ArrayList<Node> inBound;
	public int visitCount;
	public int number;
	public Node(int n) {
		this.outBound = new ArrayList<Node>();	
		//this.inBound = new ArrayList<Node>();	
		this.visitCount = 0;
		this.number = n;
	}
	
	public void addNode(Node n){
		this.outBound.add(n);
		//n.inBound.add(n);
	}
}
