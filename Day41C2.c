#include <stdlib.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    
    int freq[26] = {0};
    
    // Count frequency of each task
    for(int i = 0; i < tasksSize; i++)
        freq[tasks[i] - 'A']++;
    
    int maxFreq = 0;
    
    for(int i = 0; i < 26; i++)
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    
    int countMax = 0;
    
    for(int i = 0; i < 26; i++)
        if(freq[i] == maxFreq)
            countMax++;
    
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    
    int result = partCount * partLength + countMax;
    
    if(result < tasksSize)
        return tasksSize;
    
    return result;
}
