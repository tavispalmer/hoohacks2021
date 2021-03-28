public class Ships {
    Ships Carrier;
    Ships Battleship;
    Ships Destroyer;
    Ships Submarine;
    Ships PatrolBoat;

    Ships[] arr = new Ships[5];

    private int numi;
    private

    public Ships(int num) {
        this.num = numi;


        Carrier = new Ships(5);
        Battleship = new Ships(4);
        Destroyer = new Ships(3);
        Submarine = new Ships(3);
        PatrolBoat= new Ships(2);

        arr[0] = Carrier;
        arr[1] = Battleship;
        arr[2] = Destroyer;
        arr[3] = Submarine;
        arr[4] = PatrolBoat;
    }
}
