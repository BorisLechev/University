function reduceVegetables(name) {
    let obj = {};
    obj["name"] = name;
    obj["count"] = 1;

    fetch("/vegetables", {
        method: "post",
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(obj)
    })
    .then(response => {
        return response.json();
    })
    .then(data => {
        let element = document.getElementById(name);
        element.innerHTML = data;
    })
    .catch(err => {
        console.error(err);
    });
}