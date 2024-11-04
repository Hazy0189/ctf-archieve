(function() {
    var socket = io();
    var game_id;
    const topRow = [0, 1, 2]; // Only use top row squares

    socket.on('connect', () => socket.emit('client_new_game'));

    socket.on('server_new_game', (data) => {
        game_id = data.game_id;
        console.log("Game started. ID:", game_id);
    });

    socket.on('server_board_update', (boardData) => {
        console.log("Current board : ", boardData.board)
        if (boardData.winner !== -1) {
            if (boardData.winner === 0) {
                console.log("Player won! Flag:", boardData.flag);
            } else if (boardData.winner === 1) {
                console.log("Opponent won...");
            } else {
                console.log("It's a tie.");
            }
            return;
        }

        let square = topRow.find(s => boardData.board[s] === null);
        if (square !== undefined && game_id) {
            console.log("Attempting player move on square:", square);
            socket.emit('client_check_square_valid', { game_id, square });
        }
    });

    socket.on('server_check_square_valid', (response) => {
        if (response.is_valid && game_id) {
            socket.emit('client_place_square', { game_id, square: response.square });
            console.log("Placed player move on square:", response.square);
        }
    });
})();
