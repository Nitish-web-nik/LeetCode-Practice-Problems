
class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Initialize a max heap (priority queue in reverse)
        std::priority_queue<int> maxHeap;
        
        // Add all numbers into the heap
        for (int num : nums) {
            maxHeap.push(num);
        }

        long long score = 0;

        // Apply exactly k operations
        for (int i = 0; i < k; ++i) {
            // Extract the maximum element
            int maxElement = maxHeap.top();
            maxHeap.pop();

            // Increase the score by the maximum element
            score += maxElement;

            // Replace the element with ceil(maxElement / 3)
            int reducedElement = std::ceil(maxElement / 3.0);
            maxHeap.push(reducedElement);
        }

        // Return the maximum possible score
        return score;
    }
};
