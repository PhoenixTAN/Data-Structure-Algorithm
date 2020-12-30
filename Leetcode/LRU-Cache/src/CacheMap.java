import java.util.HashSet;
import java.util.Set;

/*
Author: Ziqi Tan
*/
public class CacheMap {
	
	private int capacity;
	private Set<Integer> keySet;
	private static final int MAXIMUM_CAPACITY = 1 << 30;
	private DoublyLinkedList[] table;
	private DoublyLinkedList priorityQueue;
	
	/**
	 * Constructor
	 * */
	public CacheMap(int _capacity) {
		capacity = _capacity;
		keySet = new HashSet<Integer>();
		table = new DoublyLinkedList[getTableSize()];
		priorityQueue = new DoublyLinkedList();
	}
	
	/**
	 * get operation
	 * */
	public int get( int key ) {
		int hash = getHash(key);
		if( table[hash] == null ) {
			return -1;
		}
		
		DoublyLinkedList list = table[hash];
		int value = list.getValueByKey(key);
		if( value == -1 ) {
			return value;
		}
		priorityQueue.remove(key);
		priorityQueue.addFirst(new Node(key, value));
		return value;
	}
	
	/**
	 * put operation
	 * */
	public void put( int key, int value ) {
		// if key exists, overwrite value and add to most recent used.
		if( keySet.contains(key) ) {
			int hash = getHash(key);
			DoublyLinkedList list = table[hash];
			list.setValueByKey(key, value);
			priorityQueue.remove(key);
			priorityQueue.addFirst(new Node(key, value));
			return ;
		}
		
		// if key does not exists
		if( size() == capacity ) {
			System.out.println("Full");
            // if the cache is full               
            // remove and retrieve the last key of the priority list
            Node lru = priorityQueue.removeLast();
            keySet.remove(lru.key);
            // then delete the LRU node
            int hash = getHash(lru.key);
            DoublyLinkedList list = table[hash];
            System.out.println("Try to remove key: " + lru.key);
            list.remove(lru.key);
        }
		
		// put
		int hash = getHash(key);
		if( table[hash] == null ) {
			table[hash] = new DoublyLinkedList();
		}
		DoublyLinkedList list = table[hash];
		list.addFirst(new Node(key, value));
		keySet.add(key);
		priorityQueue.addFirst(new Node(key, value));
		
	}
	
	/**
	 * getter
	 * */
	public int size() {
		return keySet.size();
	}
	
	public Set<Integer> keySet() {
		return keySet;
	}
	
	/**
	 * helper functions
	 * */
	/**
     * Returns a power of two size for the given target capacity.
     */
    private int getTableSize() {
        int n = capacity - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }
    
    private int getHash(int key) {
    	return key % table.length;
    }
}
