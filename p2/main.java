
import java.util.*;

class GraphTest {
	public static void main(String[] args) {
		//System.out.print(args[0] + " nodes ");
		//System.out.print(args[1] + " edges ");
		//If it passed here that means it has the variables
		//Generate agency matrix
		int nodeCount = Integer.parseInt(args[0]);
		int edgeCount = Integer.parseInt(args[1]);
		int repeatCount = Integer.parseInt(args[2]);
		int mode = Integer.parseInt(args[3]);
		int connectedCount = 0;
		int graphLimit = 0;
		Random diceRoller = new Random();

		while(repeatCount > 0){ 
			ArrayList<Node> nodeList = new ArrayList<Node>();
			boolean[][] edgeList = new boolean[nodeCount][nodeCount];
			int i,k;

			//Create nodes
			for (i = 0; i < nodeCount; i++){
				//Default to false for the edgeList
				for(k = 0; k < nodeCount; k++){
					edgeList[i][k] = false;
				}
				nodeList.add(new Node(i));
			}

			int vertexA = 0;
			int vertexB = 0;
			//Create edges
			for (i = 0; i < edgeCount; i++) {
				while(true){	
					vertexA = diceRoller.nextInt(nodeCount);
					vertexB = diceRoller.nextInt(nodeCount);
					if(edgeList[vertexA][vertexB] || vertexA == vertexB){
						continue;
					}
					edgeList[vertexA][vertexB] = true;
					edgeList[vertexB][vertexA] = true;
					nodeList.get(vertexA).addNode(nodeList.get(vertexB));
					nodeList.get(vertexB).addNode(nodeList.get(vertexA));
					break;
				}
			}

			//Verify if bidirectional
			for(Node n: nodeList ){
				for(Node n2: n.outBound ){
					if(n2.outBound.indexOf(n) == -1){
						System.exit(1);
					}
				}
			}

			switch(mode){
				case 0: //Check of connectedness
					if(!checkConnected(nodeList)){
						//connectedCount++;
						//System.out.print("Disconnected \n");
					}else{
						connectedCount++;
						//System.out.print("Connected \n");
					}
					break;
				case 1:
					if(checkConnected(nodeList)){
						System.out.print(Walk(diceRoller, nodeList) + ",");
						graphLimit++;
					}
					break;
			}
			if(graphLimit == 5){
				break;
			}
			repeatCount--;
		}
		switch(mode){
			case 0:
				System.out.print(connectedCount);
			break;
		}
	}

	public static boolean checkConnected(ArrayList<Node> nodeList){
		boolean isDisconnect = false;
		//Clear visitcount
		for(Node n: nodeList){
			n.visitCount = 0;
		}
		DFStraverse(nodeList.get(0));
		//See if any nodes din't get visited
		for (Node n : nodeList){
			if(n.visitCount == 0){
				isDisconnect = true;
				break;
			}
		}
		return !isDisconnect;
	}

	public static void DFStraverse(Node startNode){
		startNode.visitCount++;
		for (Node node : startNode.outBound){
			if(node.visitCount == 0){
				DFStraverse(node);
			}
		}
	}

	public static int Walk(Random r, ArrayList<Node> nodeList){
		int zeroCount = 0;
		int size = 0;
		int nodeSize = nodeList.size();
		//Clear visitcount
		for(Node n: nodeList){
			n.visitCount = 0;
		}
		Node currNode = nodeList.get(r.nextInt(nodeSize - 1));
		currNode.visitCount++;
		zeroCount++;
		while(zeroCount < nodeSize){
			size = currNode.outBound.size();
			if(size > 1){
				currNode = currNode.outBound.get(r.nextInt(size)); //Pick one node
			}else{
				currNode = currNode.outBound.get(0);
			}
			if(currNode.visitCount == 0){
				zeroCount++;
				//System.out.println(zeroCount + "  "+ nodeList.size());
			}
			/*
			for(Node n: nodeList){
				if(n.visitCount == 0){
					System.out.print("Node - " + n.number);
					for(Node node: n.outBound){
						System.out.print( " - " + node.number);
					}
					System.out.println();
				}
			}
			*/
			currNode.visitCount++;
		}
		int sum = 0;
		for(Node n: nodeList){
			sum += n.visitCount;
		}
		return sum;
	}
}
