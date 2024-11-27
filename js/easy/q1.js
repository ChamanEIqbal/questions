/*
 * In a futuristic cyberwarfare setting, two factions, the Global Cyber Defense Alliance (GCDA) 
 * and the Nexus Collective, are battling for control over a powerful AI called the Quantum Core. 
 * The only way to unlock its secrets is by merging two sets of encryption keys scattered across 
 * two secure data vaults. Your task is to combine two arrays, representing these encryption keys, 
 * into a single array that contains only the unique keys—no duplicates. Efficiently solving this 
 * will unlock the Quantum Core and secure victory for your faction!
 * 
 * Your faction had a programmer before; but they were incapable of producing the correct union of
 * these keys! It is upto you to take for the challenge! Good Luck out there, chief!
 *
 * INPUTS:
 * - Two arrays (A and B) of integers representing the encryption keys.
 * - The size of each array is N for A and M for B.
 * 
 * OUTPUT:
 * - A new array containing the unique keys from both arrays, with no duplicates.
 * 
 * CONSTRAINTS:
 * - 1 ≤ N, M ≤ 10^6
 * - Array elements are integers.
 *
 * EXAMPLE 1:
 * INPUT:
 * A = {1, 2, 3, 4}
 * B = {3, 4, 5, 6}
 *
 * OUTPUT:
 * {1, 2, 3, 4, 5, 6}
 *
 * EXAMPLE 2:
 * INPUT:
 * A = {1, 2, 2, 3, 5}
 * B = {3, 4, 4, 5}
 *
 * OUTPUT:
 * [1, 2, 3, 4, 5]
*/

function unionOfKeys(keyNexa1, keyNexa2) {
    let unionNexa = keyNexa1.concat(keyNexa2);

    unionNexa = unionNexa.filter(function(value, index.self)) {
        return self.indexOf(value) === index;
    }

    console.log(unionNexa);
}

function main() {
    let keyNexa1 = [1,2,3];
    let keyNexa2 = [3,4,5];

    unionOfKeys(keyNexa1, keyNexa2);
}