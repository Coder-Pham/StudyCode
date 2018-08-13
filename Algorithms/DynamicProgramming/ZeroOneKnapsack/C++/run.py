import os
import time


NUM_TESTS = 100
WATA = "dp"
YUKO = "brute"


def run_test():
    # os.system("python3 gen.py |& tee -a in.txt")
    os.system("python3 gen.py > _in.txt")
    os.system("./{0} < _in.txt > _ans.txt".format(YUKO))
    begin_time = time.time()
    os.system("./{0} < _in.txt > _out.txt".format(WATA))
    time_taken = time.time() - begin_time

    ans_lines = []
    out_lines = []

    with open ("_ans.txt", 'r') as f:
        for line in f:
            ans_lines.append(line)

    with open ("_out.txt", 'r') as f:
        for line in f:
            out_lines.append(line)

    if len(ans_lines) != len(out_lines):
        print("WA")
        return False
    else:
        for i in range(len(ans_lines)):
            if out_lines[i] != ans_lines[i]:
                print("WA")
                return False

    os.system("rm _in.txt _ans.txt _out.txt")
    print("AC - time taken: {0:.6f}".format(time_taken))
    return True


def main():
    cnt = 0
    os.system("make test")
    while (cnt < NUM_TESTS):
        cnt += 1
        print("#Test {0}: ".format(cnt), end='')
        result = run_test()
        if result == False:
            break
    if result == True:
        print("All accepted!")


if __name__ == "__main__":
    main()
