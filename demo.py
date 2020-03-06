from collections import OrderedDict


def getMachine():
    n = int(raw_input())
    a = list(map(str,raw_input().strip().split()))[:n]
    for i in range(0, len(a)):
        result[a[i]] = []; 
    return a

def getMachineMapping():
    r = int(raw_input())
    while r>0:
        domain = str(raw_input())
        machineToUrlMapping_count = int(raw_input())
        machineToUrlMapping = list(map(str,raw_input().strip().split()))[:machineToUrlMapping_count]
        data[domain] = machineToUrlMapping
        watch[domain] = -1
        r -= 1

def compileUrl(query):
    splitted_url = query.split("/")
    current_domain = splitted_url[0]
    current_domain_machines = data[current_domain]
    if len(splitted_url)==2:
        machine_up_query = splitted_url[1].split("machine_down?ip=")
        machine_down_query = splitted_url[1].split("machine_up?ip=")
        
        if (len(machine_up_query)==2 and machine_up_query[1] in a):
            data[current_domain].remove(machine_up_query[1])
        elif (len(machine_down_query)==2 and machine_down_query[1] in a):
            data[current_domain].append(machine_down_query[1])
        elif len(current_domain_machines) > 0:
            watch[current_domain] += 1
            watch[current_domain] %= len(current_domain_machines)
            result[data[current_domain][watch[current_domain]]].append(query)
            
    elif len(current_domain_machines) > 0:
        watch[current_domain] += 1
        watch[current_domain] %= len(current_domain_machines)
        result[data[current_domain][watch[current_domain]]].append(query)

def getQuery():
    q = int(raw_input())
    while q>0:
        query = str(raw_input())
        compileUrl(query)
        q-=1
        

def printSol():
    for key, value in result.items():
        print(key)
        for i in range(0, len(value)):
            print(value[i])

a = []
result = OrderedDict()
watch = {}
data = {}
a = getMachine()
getMachineMapping()
getQuery()
printSol()


