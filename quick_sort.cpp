void swapPlayers(vector<Player> *players, int indexA, int indexB) {
    Player temp = (*players)[indexA];
    (*players)[indexA] = (*players)[indexB];
    (*players)[indexB] = temp;
}

int partition(vector<Player> *players, int minI, int maxI) {
    // Pivod is the last element of the array.
    Player pivod = (*players)[maxI];
    
    // Minial score index is an index on the last element with a score lower than the pivot.
    int minimalScoreIndex = minI - 1;
    
    for (int iterPlayer = minI; iterPlayer <= maxI - 1; ++iterPlayer) {
        // Player's score and name are lower than the pivot, we move it to the minimalScoreIndex.
        if (
            (*players)[iterPlayer].score > pivod.score
            or (
                (*players)[iterPlayer].score == pivod.score
                && (*players)[iterPlayer].name <= pivod.name
            )
        ) {
            minimalScoreIndex++;
            swapPlayers(players, minimalScoreIndex, iterPlayer);
        }
    }

    minimalScoreIndex++;
    // Swap the pivot to the minimalScoreIndex.
    swapPlayers(players, minimalScoreIndex, maxI);
    
    return minimalScoreIndex;
}

void quickSort(vector<Player> *players, int minI, int maxI) {
    if (minI < maxI) {
        // partitionIndex is at the right place.
        int partitionIndex = partition(players, minI, maxI);
        // Recursivly call quickSort on the lowest and higest bounded array.
        quickSort(players, minI, partitionIndex - 1);
        quickSort(players, partitionIndex + 1, maxI);
    }
}

vector<Player> comparator(vector<Player> players) {
    quickSort(&players, 0, players.size() - 1);
    
    return players;
}
