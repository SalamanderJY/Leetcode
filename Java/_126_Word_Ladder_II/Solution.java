package _126_Word_Ladder_II;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Solution {
    public List<List<String>> findLadders(String start, String end, Set<String> dict) {
    	List<List<String>> result = new ArrayList<>();
    	// use set for current level instead of queue to avoid calculating ladder for duplicated word
    	Set<String> cur = new HashSet<>();
    	Set<String> visited = new HashSet<>();
    	
    	// word, and all words that can direct lead to this word in path
    	Map<String, List<String>> fatherMap = new HashMap<>();
    	cur.add(start);
    	
    	boolean found = false;
    	
    	// length of every word
    	int wordLen = start.length();
    	
    	while(!cur.isEmpty() && !found) {
    		Set<String> next = new HashSet<>();
    		
    		for(String str : cur) {
    			for(int i = 0; i < wordLen; i++) {
    				StringBuilder sb = new StringBuilder(str);
    				for(char c = 'a'; c <= 'z'; c++) {
    					sb.setCharAt(i, c);
    					String word = sb.toString();
    					if(word.equals(end)) {
    						found = true;
    					}
    					if(dict.contains(word) && !visited.contains(word) ||
    							word.equals(end)){
    						next.add(word);
    						if(!fatherMap.containsKey(word)){
    							fatherMap.put(word, new ArrayList<>());
    						}
    						fatherMap.get(word).add(str);
    					}
    				}
    			}
    		}
    		
    		cur = next;
    		visited.addAll(cur);
    	}
    	//确定能够找到一条以上路径到达end
    	if(found) {
    		List<String> path = new ArrayList<>();
    		DFS(start, end, path, fatherMap, result);
    	}
    	
    	return result;
    }
    
    // construct paths based father map
    private void DFS(String start, String end, List<String> path, 
    		         Map<String, List<String>> fatherMap, List<List<String>> result) {
    	path.add(end);
    	if(end.equals(start)) {
    		if(path.size() == 1) {
    			path.add(start);
    		}
    		result.add(new ArrayList<>(path));
    		Collections.reverse(result.get(result.size() - 1));
    	} else {
    		List<String> que = fatherMap.get(end);
    		for(String word : que) {
    			DFS(start, word, path, fatherMap, result);
    		}
    	}
    	path.remove(path.size() - 1);
    }
}
