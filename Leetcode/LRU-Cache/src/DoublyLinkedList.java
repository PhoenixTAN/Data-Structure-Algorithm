/*
Author: Ziqi Tan
*/
public class DoublyLinkedList {
	private Node head;
	private Node tail;
	private int size;
	
	/**
	 * Constructor
	 * */
	public DoublyLinkedList() {
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		head.next = tail;
		head.pre = null;
		tail.pre = head;
		tail.next = null;
		size = 0;
	}
	
	/**
	 * Add a node in the head of the linked list
	 * */
	public void addFirst(Node node) {
		node.next = head.next;
		node.pre = head;
		
		head.next.pre = node;
		
		head.next = node;
		size++;
	}
	
	/**
	 * Remove a node by key
	 * */
	public void remove(int key) {
		Node p = head.next;
		while( p != null ) {
			if( p.key == key ) {
				p.pre.next = p.next;
				p.next.pre = p.pre;
				p = null;
				size--;
				return ;
			}
			p = p.next;
		}
		System.out.println("remove error...");
	}
	
	/**
	 * Remove the last node of the list and return this node
	 * */
	public Node removeLast() {
		if( tail.pre == head ) {
			return null;
		}
		Node last = tail.pre;
		last.pre.next = tail;
		tail.pre = last.pre;
		return last;
	}
	
	/**
	 * get value by key
	 * */
	public int getValueByKey(int key) {
		Node p = head.next;
		while( p != null ) {
			if( p.key == key ) {
				return p.value;
			}
			p = p.next;
		}
		
		System.out.println("Cannot find that key");
		return -1;
	}
	
	/**
	 * set value by key
	 * */
	public void setValueByKey(int key, int value) {
		Node p = head.next;
		while( p != null ) {
			if( p.key == key ) {
				p.value = value;
				return ;
			}
			p = p.next;
		}
		
		System.out.println("Cannot find that key");
	}
	
	/**
	 * getter for linked size
	 * */
	public int size() {
		return size;
	}
}
