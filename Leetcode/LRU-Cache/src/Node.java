/*
Author: Ziqi Tan
*/
public class Node {
	public int key;
	public int value;
	public Node pre;
	public Node next;
	
	/**
	 * Constructor
	 * */
	public Node( int _key, int _value) {
		key = _key;
		value = _value;
		pre = null;
		next = null;
	}
}
