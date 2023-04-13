/* Lab #4
 * 1. Understand teh team project
 * 2. Create an algorithm - psuedocode
 * 3. Find bigO complexity
 *
 * Input: some filename
 * Output: word pairs from file filename and their frequency (look at section 4 in zybooks)
 */

/* Funciton prototypes
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
