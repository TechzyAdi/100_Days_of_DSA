void dfs(int room, int** rooms, int* roomsColSize, int* visited) {
    visited[room] = 1;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];

        if (!visited[key]) {
            dfs(key, rooms, roomsColSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];

    // Initialize visited
    for (int i = 0; i < roomsSize; i++)
        visited[i] = 0;

    // Start from room 0
    dfs(0, rooms, roomsColSize, visited);

    // Check if all visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i])
            return false;
    }

    return true;
}
