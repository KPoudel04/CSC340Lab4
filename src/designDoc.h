/* ** Lab #4 **
 * 1. Understand teh team project
 * 2. Create an algorithm - psuedocode
 * 3. Find bigO complexity
 *
 * Input: some filename
 * Output: word pairs from file filename and their frequency (look at section 4 in zybooks)
 */

/* ** Funciton prototypes **
 * 
 * Converts a text file with the name fname into a list of senteces.  The list of sentences will be
 * stored in the sentences vector in the same order as it appears in the input file.
 *
 * void sentenceSplitter(string& fname, vector<string>& sentences);
 
 *
 * Given a list of sentences stored in the first argument sentences, this function indentifies all the
 * unique word-pairs and each word-pairs's frequency.  The identified (word-pair, frequency);s will be
 * stored into worpariFreq_map, which is a map of (key, value) pairs.  The key of this map a word-pair
 * and the value is the frequency of this word-pair.
 *
 * void wordpairMapping(vector<string>& sentences, map<pair<string, string> int>& wordpairFreq_map);
 */

/* ** Algorithms **
 * 
 * sentenceSplitter
 *
 * While (not at end of file)
 *  If (current character is ., ?, !, or :)
 *    Store current string in sentence vector
 *    Clear current string
 *  Else
 *    Add current character to current string
 * (END sentenceSplitter)
 *
 *
 * wordpairMapping
 *
 * Create a sentence vector with output from sentenceSplitter()
 * For (every sentence in sentence vector)
 *  For (i-th word in sentence vector-1)
 *    Remove all no alphabetical/numerical characters from ith word
 *    For (ith+1 word in sentence vector)
 *      Remove all no alphabetical/numerical characters from ith+1 word
 *      If pair(word i, word i+1) exist in map (not order specific)
 *        Increment value of pair
 *      Else
 *        Create pair(word i, word i+1) pair in map
 *        Set value to 1
 * (END wordpairMapping)
 */
