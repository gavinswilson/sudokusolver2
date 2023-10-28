from grid import sudoku_grid
import numpy as np

puzzle = sudoku_grid(9,9,1,9)

# print(puzzle.get_rows())
# print(puzzle.get_cols())
puzzle.set_value(2,2,2)
puzzle.set_value(5,5,1)
puzzle.set_value(1,1,9)


puzzle.remove_knowns()
# puzzle.print_grid()
# puzzle.print_opts()
# puzzle.print_regions()
# print(puzzle.get_value(2,2))
# print(puzzle.get_opts(2,2))
# puzzle.remove_knowns()
# puzzle.print_grid()
# puzzle.print_opts()
# puzzle.print_regions()
# mask=np.uint16(puzzle.get_mask())

# print(np.binary_repr(opts))
# print(np.binary_repr(mask))
puzzle.print_opts()
# for i in range(1, 9):
#         for j in range(1, 9):
#                 print(np.binary_repr(puzzle.get_opts(i,j)))
