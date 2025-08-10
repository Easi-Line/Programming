export class ProjectController {
    private projectService: any; // Replace 'any' with the actual type of your project service

    constructor(projectService: any) { // Replace 'any' with the actual type of your project service
        this.projectService = projectService;
    }

    public createProject(req: any, res: any): void {
        const projectData = req.body;
        this.projectService.createProject(projectData)
            .then((project: any) => res.status(201).json(project))
            .catch((error: any) => res.status(400).json({ error: error.message }));
    }

    public getProjects(req: any, res: any): void {
        this.projectService.fetchProjects()
            .then((projects: any) => res.status(200).json(projects))
            .catch((error: any) => res.status(500).json({ error: error.message }));
    }

    public updateProject(req: any, res: any): void {
        const projectId = req.params.id;
        const projectData = req.body;
        this.projectService.updateProject(projectId, projectData)
            .then((updatedProject: any) => res.status(200).json(updatedProject))
            .catch((error: any) => res.status(400).json({ error: error.message }));
    }
}