#include "DigitStringDiv1.cpp"

int main(int argc, char **argv)
{
  class DigitStringDiv1 TheClass;
  long long retval;
  string S;
  int X;

  if (argc == 3) {
    S = argv[1];
    X = atoi(argv[2]);
  } else {

    if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

   if (atoi(argv[1]) == 0) {
      S = "0";
      X = 1;
    }

   if (atoi(argv[1]) == 1) {
      S = "101";
      X = 9;
    }

   if (atoi(argv[1]) == 2) {
      S = "471";
      X = 47;
    }

   if (atoi(argv[1]) == 3) {
      S = "2222";
      X = 97;
    }

   if (atoi(argv[1]) == 4) {
      S = "95847362";
      X = 436;
    }

   if (atoi(argv[1]) == 5) {
      S = "102030405";
      X = 85;
    }

    if (atoi(argv[1]) == 6) { S = "8034151889109199226907"; X = 368249157; }
    if (atoi(argv[1]) == 7) { S = "54019091675924410392006963001976"; X = 33857108; }
    if (atoi(argv[1]) == 8) { S = "949778566115406970397000000000000000000079641169"; X = 694874013; }
    if (atoi(argv[1]) == 9) { S = "990450814731595674899314817951534213891202482671"; X = 777444111; }
    if (atoi(argv[1]) == 10) { S = "906708300000000816661861190246822256891226113143"; X = 13879163; }
    if (atoi(argv[1]) == 11) { S = "547371145238239979608276364147467162445006834154"; X = 26862; }
    if (atoi(argv[1]) == 12) { S = "550000096205335065730009666579861000000769420768"; X = 75676722; }
    if (atoi(argv[1]) == 13) { S = "957837542544882028114572037810101728066730780324"; X = 536624519; }

  }

  retval = TheClass.count(S, X);
  cout << "S=" << S << "    X=" << X << "    Answer=" << retval << endl;

  exit(0);
}
