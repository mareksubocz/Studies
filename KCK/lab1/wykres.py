import matplotlib.pyplot as plt
import csv
from statistics import mean

last_values = []


def read_table(file):
    global last_values
    effort = []
    values = []
    with open(file) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for line_count, row in enumerate(csv_reader):
            if line_count == 0:
                continue
            elif line_count == 200:
                last_values.append(list(map(lambda x: float(x) * 100, row[2:])))
            sum = 0
            for column_count, field in enumerate(row):
                if column_count == 0:
                    continue
                elif column_count == 1:
                    effort.append(int(field)/1000)
                else:
                    sum += float(field) * 100
            values.append(sum/32)
    return effort, values


t_rsel, v_rsel = read_table('rsel.csv')
t_cel_rs, v_cel_rs = read_table('cel-rs.csv')
t_2cel_rs, v_2cel_rs = read_table('2cel-rs.csv')
t_cel, v_cel = read_table('cel.csv')
t_2cel, v_2cel = read_table('2cel.csv')
# plt.figure(figsize=(7, 7))

plt.rcParams["font.family"] = "serif"
f, (ax1, ax2) = plt.subplots(nrows=1, ncols=2)
ax1.set_ylim(60, 100)
ax1.set_xlim(0, 500)
ax1.tick_params(direction='in', right=True)
ax1.grid(True, linestyle='dotted')
ax1.set_xlabel('Rozegranych gier (x1000)')
ax1.set_ylabel('Odsetek wygranych gier [%]')
secax = ax1.twiny()
secax.set_xlabel('Pokolenie')
# secax.plot(range(201))
secax.set_xlim(0, 200)
secax.set_xticks(range(0, 201, 40))
secax.tick_params(direction='in')
ax1.plot(t_rsel, v_rsel, 'b', label='1-Evol-RS', linewidth=.9, markevery=25, marker='o', markeredgecolor='black', markersize=4)
ax1.plot(t_cel_rs, v_cel_rs, 'g', label='1-Coev-RS', linewidth=.9, markevery=25, marker='v', markeredgecolor='black', markersize=4)
ax1.plot(t_2cel_rs, v_2cel_rs, 'r', label='2-Coev-RS', linewidth=.9, markevery=25, marker='D', markeredgecolor='black', markersize=4)
ax1.plot(t_cel, v_cel, 'k', label='1-Coev', linewidth=.9, markevery=25, marker='s', markeredgecolor='black', markersize=4)
ax1.plot(t_2cel, v_2cel, 'm', label='2-Coev', linewidth=.9, markevery=25, marker='d', markeredgecolor='black', markersize=4)
ax1.legend(numpoints=2)

ax2.yaxis.tick_right()
for tick in ax2.get_xticklabels():
    tick.set_rotation(20)
ax2.tick_params(direction='in', top=True)
ax2.set_ylim(60, 100)
ax2.grid(True, linestyle='dotted')
box = ax2.boxplot(
    last_values,
    1,  # notched
    'b+',  # points
        labels=['1-Evol-RS', '1-Coev-RS', '2-Coev-RS', '1-Coev', '2-Coev'])
for i in range(len(last_values)):
    ax2.scatter(i+1,
                mean(last_values[i]),
                color="b",
                edgecolors='black',
                linewidths="0.1")
for e in box['medians']:
    e.set_color('r')
for e in box['boxes']:
    e.set_color('b')
for e in box['means']:
    e.set_color('b')
for e in box['whiskers']:
    e.set_color('b')
    e.set_linestyle('dashed')
# f.rcParams["axes.linewidth"] = '0.25'
plt.savefig('myplot.pdf')
plt.show()
plt.close()
