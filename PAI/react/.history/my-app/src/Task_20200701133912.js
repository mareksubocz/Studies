import React from 'react';

// constructor(props){
//     super(props);
//     this.state = {
//         tekst: "Przyklad",
//         checked: true
//     };
// };

function Task(props) {
    return ( 
        <div className="task" style={{display: props.visible === "true" ? "block" : "none"}}>
            <input type = "checkbox" id="ajdi" name="ajdi" {props.checked} == "true" ? checked/>
            <label for="ajdi"> {props.text}</label>
        </div>
        
    );
}

export default Task